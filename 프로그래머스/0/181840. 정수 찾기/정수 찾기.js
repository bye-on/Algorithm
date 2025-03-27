function solution(num_list, n) {
    var answer = 0;
    for(let num of num_list)
    {
        if(num == n)
            answer = 1;
    }
    return answer;
}