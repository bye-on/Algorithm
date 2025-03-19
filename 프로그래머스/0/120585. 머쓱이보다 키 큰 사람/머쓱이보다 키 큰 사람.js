function solution(array, height) {
    var answer = 0;
    
    answer = array.filter(e => e > height).length;
    
    return answer;
}