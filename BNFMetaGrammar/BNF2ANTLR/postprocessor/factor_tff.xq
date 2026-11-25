(: Guard the specific productions used in the language-preservation argument.
   Compare complete terminal tokens so whitespace inside literals is significant. :)
declare function local:matches($root, $name, $expected) {
  let $rule := $root//parserRuleSpec[RULE_REF/text() = $name]
  return count($rule) = 1 and count($rule/*[not(self::exceptionGroup)]) = 4
         and string-join($rule/ruleBlock//text(), ' ') = $expected
};

let $root := .
let $logic := //parserRuleSpec[RULE_REF/text() = 'tff_logic_formula']
let $unit := //parserRuleSpec[RULE_REF/text() = 'tff_unit_formula']
let $helpers := //parserRuleSpec[RULE_REF/text() = (
  'bnf2antlr_tff_formula_term', 'bnf2antlr_tff_infix_tail')]
return
  if (exists($helpers) or exists(//actionBlock | //argActionBlock | //delegateGrammars
                                | //exceptionHandler | //finallyClause)
      or not(local:matches($root, "tff_logic_formula", "tff_unitary_formula | tff_unary_formula | tff_binary_formula | tff_defined_infix | txf_definition | txf_sequent")
        and local:matches($root, "tff_unit_formula", "tff_unitary_formula | tff_unary_formula | tff_defined_infix")
        and local:matches($root, "tff_unitary_formula", "tff_quantified_formula | tff_atomic_formula | txf_unitary_formula | '(' tff_logic_formula ')'")
        and local:matches($root, "txf_unitary_formula", "variable")
        and local:matches($root, "tff_unary_formula", "tff_prefix_unary | tff_infix_unary")
        and local:matches($root, "tff_infix_unary", "tff_unitary_term infix_inequality tff_unitary_term")
        and local:matches($root, "tff_defined_infix", "tff_unitary_term defined_infix_pred tff_unitary_term")
        and local:matches($root, "tff_unitary_term", "tff_atomic_formula | defined_term | txf_tuple | variable | '(' tff_logic_formula ')'")
        and local:matches($root, "tff_binary_formula", "tff_binary_pair | tff_binary_list")
        and local:matches($root, "tff_binary_pair", "tff_unit_formula nonassoc_connective tff_unit_formula")
        and local:matches($root, "tff_binary_list", "tff_or_formula | tff_and_formula")
        and local:matches($root, "tff_or_formula", "tff_unit_formula Vline tff_unit_formula | tff_or_formula Vline tff_unit_formula")
        and local:matches($root, "tff_and_formula", "tff_unit_formula '&amp;' tff_unit_formula | tff_and_formula '&amp;' tff_unit_formula")))
  then error((), 'Expected the original action-free TFF rule structure and unused helper names')
  else (
    replace value of node $logic/ruleBlock with
      " tff_unit_formula
      ( nonassoc_connective tff_unit_formula
      | Vline tff_unit_formula ( Vline tff_unit_formula )*
      | '&amp;' tff_unit_formula ( '&amp;' tff_unit_formula )*
      )?
    | txf_definition
    | txf_sequent",
    replace value of node $unit/ruleBlock with
      " tff_quantified_formula
    | tff_prefix_unary
    | bnf2antlr_tff_formula_term bnf2antlr_tff_infix_tail?
    | ( defined_term | txf_tuple ) bnf2antlr_tff_infix_tail",
    insert node "

bnf2antlr_tff_formula_term
    : tff_atomic_formula
    | variable
    | '(' tff_logic_formula ')'
    ;

bnf2antlr_tff_infix_tail
    : ( defined_infix_pred | infix_inequality ) tff_unitary_term
    ;
" after $unit
  )
