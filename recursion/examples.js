function iter(it) {
    let total = 0;
    for (let i = 1; i <= it; i++) {
        if (i === 1) {
            total = i;
        } else {
            total *= i;
        }
    }
    console.log(total);
    console.log(1*2*3*4*5);
}

function rec(it) {
    if (it === 1) {
        return it;
    }
    return it * rec(it - 1);
}

console.log(rec(5));
// iter(5);


/**
 * 5
 */