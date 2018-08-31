<?php

// https://www.hackerrank.com/challenges/magic-square-forming/problem

function formingMagicSquare($s) {
    $pre = [
            [[8, 1, 6], [3, 5, 7], [4, 9, 2]],
            [[6, 1, 8], [7, 5, 3], [2, 9, 4]],
            [[4, 9, 2], [3, 5, 7], [8, 1, 6]],
            [[2, 9, 4], [7, 5, 3], [6, 1, 8]], 
            [[8, 3, 4], [1, 5, 9], [6, 7, 2]],
            [[4, 3, 8], [9, 5, 1], [2, 7, 6]], 
            [[6, 7, 2], [1, 5, 9], [8, 3, 4]], 
            [[2, 7, 6], [9, 5, 1], [4, 3, 8]],
    ];
    
    $min_cost = null;
    foreach($pre as $item) {
        $cost = 0;
        for($i=0; $i<3; $i++) {
            for($j=0; $j<3; $j++) {
                $cost += abs($s[$i][$j] - $item[$i][$j]);
            }
        }
        $min_cost = is_null($min_cost) ? $cost : min([$cost, $min_cost]);
    }
    return $min_cost;
}

$s = [
    [5, 3, 4]
    [1, 5, 8]
    [6, 4, 2]
];
$result = formingMagicSquare($s);
