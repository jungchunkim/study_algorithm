import java.util.Arrays;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        
        int[] answer = new int[commands.length];
        
        int index_a=0;
        for(int i=0;i<commands.length;i++){
            int first = commands[i][0];
            int end = commands[i][1];
            int[] arr = new int[end-first+1];
            
            int index=0;
            for(int j=first-1;j<end;j++){
                arr[index++]= array[j];
            }
            Arrays.sort(arr);
            
            answer[index_a++]=arr[commands[i][2]-1];
            
        }
        return answer;
    }
}