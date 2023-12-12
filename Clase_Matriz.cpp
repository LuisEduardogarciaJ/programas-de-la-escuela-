
 
 public static Matriz traspuesta(Matriz a){
        int n=a.n;
        Matriz resultado=new Matriz(a.n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                resultado.x[i][j]=a.x[j][i];
            }
        }
        return resultado;
    }
    
  
