#include "extend.h"


struct article* article_remplisage (){
        struct article *p;

        p=(struct article*)malloc(sizeof(arti));


        printf("donner le nom de lediteur ");
        scanf("%s",p->nom_editeur);

        printf("donner l adresse_editeur ");
        scanf("%s",p->adresse_editeur);

        printf("donner le nom_journal");
        scanf("%s",p->nom_journal);

        printf("donner le redacteur ");
        scanf("%s",p->redacteur);

        printf("donner le numero_journal \n");
        scanf("%d",&p->numero_journal);

        printf("donner le nom_auteur_de_larticle : \n");
        scanf("%s",p->nom_auteur_de_larticle);

        printf("donner le adresse_auteur");
        scanf("%s",p->adresse_auteur);

        printf("donner le aarticle_titre");
        scanf("%s",p->article_titre);

        return p;
   }


   void read_article (){
        int m,n;
        FILE *f;
        struct article *pp;
        pp=(struct article*)malloc(sizeof(arti));

        f=fopen("bd_file.txt","r");

        if(f==NULL)
            printf("mission faillled ");else{

              while(fread(pp,sizeof(struct article),1,f))
              {
       printf("\n");


        printf("le nom de lediteur: %s \n",pp->nom_editeur);

        printf(" l adresse_editeur : %s \n",pp->adresse_editeur);

        printf(" le nom_journal %s \n",pp->nom_journal);

        printf(" le redacteur %s \n",pp->redacteur);

        printf("le numero_journal %i \n",pp->numero_journal);

        printf(" le nom_auteur_de_larticle :%s \n",pp->nom_auteur_de_larticle);

        printf(" le adresse_auteur %s \n",pp->adresse_auteur);

        printf("\n");
        }



    }
    fclose(f);
}

    void edit(){

            FILE *f=NULL;
            arti *pp=(struct article*)malloc(sizeof(arti));
            char name_to_find[35]="A.Crisinel";
            int found=0;
            f=fopen("bd_file.txt","r+");

            printf("Swtiching from A.crisienl to Albert crisinel !");


            while(fread(pp,sizeof(struct article),1,f)!=0 && found==0){

                if(!strcmp(pp->nom_auteur_de_larticle,name_to_find)){

                   strcpy((pp->nom_auteur_de_larticle),"Albert Crisinel");

                    fseek(f,-1 * (sizeof(struct article)),SEEK_CUR);

                    fwrite(pp,sizeof(struct article),1,f);

                    printf("\n the operation is done succesfully !");

                    found=1;
                }

            }
            fclose(f);

    }





    void Delete(){

        FILE *f,*f_temp;
        f=f_temp=NULL;
            arti *pp=(struct article*)malloc(sizeof(arti));
            char name_to_find[35]="p_coeytaux";
            int found=0;
            f=fopen("bd_file.txt","r+");
            f_temp=fopen("temp.txt","w");

            printf("deleting the article that contains p.Coeytaux  !");


            while(fread(pp,sizeof(struct article),1,f)!=0 ){

                if(!strcmp(pp->nom_auteur_de_larticle,name_to_find)){

                    continue;
                }else
                    {

                    fwrite(pp,sizeof(struct article),1,f_temp);
                     }

                }

                fclose(f);

                fclose(f_temp);

                f=fopen("bd_file.txt","w");

                f_temp=fopen("temp.txt","r");


                while(fread(pp,sizeof(struct article),1,f_temp)!=0 ){

                    fwrite(pp,sizeof(struct article),1,f);

                }
                            fclose(f);
                            fclose(f_temp);

                   printf("\n the operation of delete is done !");


            }











    void main_menu(){

        int decision;
        do{
        printf("1:Cree noveau list d article \n");
        printf("\n2:afficher les article \n");
        printf("\n3:modifier les fichier \n");
        printf("\n4:supprimer le fichier \n");
        printf("\nsvp choissir une option! (-1) pour exit  \n");
        scanf("%d",&decision);

        switch(decision){
            case 1:
                    printf("combien d article ?");
                    scanf("%d",&number_of_article);
                    f=fopen("bd_file.txt","w");
                    struct article *p=NULL;
                    for(int i=0;i<number_of_article;i++){
                    p=article_remplisage();
                    fwrite(p,sizeof(struct article),1,f);
                    }
                    fclose(f);
                    break;
            case 2 :
                    read_article();
                    break;
            case 3:
                    edit();
                    break;
            case 4:
                    Delete();
                    break;


        }
        }while(decision!=-1);


    }
