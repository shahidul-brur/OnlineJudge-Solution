main(a,b,c,x,y,z){scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z),a/=((a-=x)>0)+1,b/=((b-=y)>0)+1,c/=((c-=z)>0)+1,puts(a+b+c>=0?"Yes":"No");}