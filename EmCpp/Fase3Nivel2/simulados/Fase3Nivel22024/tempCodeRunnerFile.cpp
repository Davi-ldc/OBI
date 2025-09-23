    int r = 0;
    for(int i =0; i<=N; i++){//pra cada reta 1 3 
        for (int j = i; j<N; j++){//compara com as outras a frente 
            if(val(f[i].first, f[i].second, f[j+1].first, f[j+1].second)){
                r++;
            }
        }
    }

    cout << r;