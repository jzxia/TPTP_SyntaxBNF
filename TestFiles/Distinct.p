fof(1,axiom,
    $distinct(a,b,c) ).

tff(2,axiom,
    $distinct(a,b,c) ).
tff(p_decl,type,p: $o).
tff(3,axiom,
    ( p => $distinct(a,b,c) ) ).

thf(4,axiom,
    $distinct(a,b,c) ).
thf(q_decl,type,q: $o).
thf(5,axiom,
    ( q => $distinct(a,b,c) ) ).



