# 4280 Project 3 Static Semantics

## How to run
1. run make clean command to clean any old builds
2. run make
3. start program by typing ./P3 [testFile]

## Known tests that are failing
P3 files - goodTest3.f23
P2 files - goodFile5, goodFile7, goodFile8, goodFile9, goodFile10

## Task

### BNF
<program> -> <vars> xopen <stats> xclose
<vars>    -> empty | xdata <varList>
<varList> -> identifier : integer <Y>
<Y>       -> ; | <varList>
<exp>     -> <M> <X>
<X>       -> / <exp> | * <exp> | empty
<M>       -> <N> <Z>
<Z>       -> + <M> | empty
<N>       -> <R> - <N> | ~<N> | <R>
<R>       -> ( <exp> ) | identifier | integer
<stats>   -> <stat> <mStat>
<mStat>   -> empty | <stat> <mStat>
<stat>    -> <in> | <out> | <block> | <if> | <loop> | <assign>
<block>   -> {<vars> <stats>}
<in>      -> xin >> identifier;
<out>     -> xout << <exp>;
<if>      -> xcond [<exp> <RO> <exp>] <stat>
<loop>    -> xloop [<exp> <RO> <exp>] <stat>
<assign>  -> xlet identifier <exp>;
<RO>      -> <<(onetoken) | >> (one token) | < | >| = | %