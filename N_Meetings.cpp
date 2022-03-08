


    int maxMeetings(int start[], int end[], int n)
    {
        pair<int, int> arr[n];
        for(int i = 0; i < n; i++){
            arr[i] = {end[i], start[i]};
        }
        sort(arr, arr + n);
        int cnt = 1;
        int lastEndTime = arr[0].first;
        for(int i = 1; i < n; i++){
            if(arr[i].second > lastEndTime){
                lastEndTime = arr[i].first;
                cnt++;
            }
        }
        return cnt;
    }