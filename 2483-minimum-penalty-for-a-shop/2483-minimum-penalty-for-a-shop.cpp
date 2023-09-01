class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        int y=0;
        for(int i=0;i<n;i++) {
            if(customers[i]=='Y') {
                y++;
            } 
        }
        
        int x=0, penalty=INT_MAX, ind=-1;  
        //x -> time when shop was open but no customer came
        if(penalty>y+x) {
            penalty=y+x;
            ind=0;
        }
        for(int i=0;i<n;i++) {
            if(customers[i]=='Y') {
                y--;
            } else {
                x++;
            }
            if(penalty>y+x) {
                penalty=y+x;
                ind=i+1;
            }
        }
        return ind;
    }
};