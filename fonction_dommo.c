#include "fonction_dommo.h"
#include<stdio.h>
#include<stdlib.h>
//Question 1-a
liste insertTeteDO(liste l,int val){
    liste nouveau=(liste)malloc(sizeof(node));
    nouveau->val=val;
    nouveau->suiv=l;
    return nouveau;
}
//Question 1-b
liste insertQueueDO(liste l,int val){
    if(l==NULL)
        return insertTeteDO(l,val);
    else{
        liste p=l;
        while(p->suiv!=NULL){
            p=p->suiv;
        }
        liste nouveau=(liste)malloc(sizeof(node));
        nouveau->val=val;
        nouveau->suiv=NULL;
        p->suiv=nouveau;
        return l; 
    }
    
}
//Question 1-c
liste buildTeteDO(){
    FILE*file=fopen("fichier.txt","r");
    if(file==NULL){
        exit(1);
    }else{
        liste l=NULL;
        int val;
        while(fscanf(file,"%d",&val)==1){
            l=insertTeteDO(l,val);
        }
        fclose(file);
        return l;
    }
}
//Question 1-d
liste buildQueueDO(){
    FILE*file=fopen("fichier.txt","r");
    if(file==NULL){
        exit(1);
    }else{
        liste l=NULL;
        int val;
        while(fscanf(file,"%d",&val)==1){
            l=insertQueueDO(l,val);
        }
        fclose(file);
        return l;
    }
}

//Question 2-a
void lookupDO(liste l,int val){
    if(l==NULL){
        printf("Liste vide! Recherche impossible.\n");
        return;
    }
    liste p=l;
    int trv=0;
    while(p!=NULL){
        if(p->val==val){
            trv=1;
            break;
        }
        p=p->suiv;
    }
    if(trv){
        printf("La valeur a été trouvé dans la liste.\n");
    }else{
        printf("La valeur n'a pas été trouvé.\n");
    }
}

//Question 2-b
void lookupLastDO(liste l,int val){
    if(l==NULL){
        printf("Liste vide! Recherche impossible.\n");
        return;
    }
    liste p=l;
    int pos=0,i=1;
    while(p!=NULL){
        if(p->val==val){
            pos=i;
        }
        i++;
        p=p->suiv;
    }
    if(pos){
        printf("La valeur a été trouvé est sa derniere occurence est à la position %d de la liste\n",pos);
    }else{
       printf("La valeur n'a pas été trouvé.\n"); 
    }
}

//Question3-a
liste removeFirstDO(liste l){
    if(l!=NULL){
        liste p=l;
        l=l->suiv;
        free(p);
    }
    return l;
}

//Question 3-b
liste removeFirstOccuDO(liste l,int val){
    if(l==NULL){
        return NULL;
    }else{
        liste p=l;
        if(l->val==val){
            l=l->suiv;
            free(p);
            return l;
        }
        while(p->suiv!=NULL){
            if(p->suiv->val==val){
                liste q=p->suiv;
                p->suiv=p->suiv->suiv;
                free(q);
                break;
            }
            p=p->suiv;
        }
        return l;
    }
    
}

//Question 3-c
liste removeAlltOccuDO(liste l,int val){

}

liste_double insertTete_doubleDO(liste_double l,int val){
    liste_double nouveau=(liste_double)malloc(sizeof(noeud));
    nouveau->preced=NULL;
    nouveau->val=val;
    nouveau->suiv=l;
    if(l!=NULL){
        l->preced=nouveau;
    }
    return nouveau;
}

void displayDO(liste l){
    if(l==NULL){
        printf("Liste vide! Affichage impossible\n");
    }else{
        liste p=l;
        printf("La liste chainé est la suivante:\n [ ");
        while(p!=NULL){
            printf("%d ",p->val);
            p=p->suiv;
        }
        printf("]\n");
    }
}

void printInOrderDO(liste_double l){
    if(l==NULL){
        printf("Liste vide! Affichage impossible\n");
    }else{
        liste_double p=l;
        printf("La liste doublement chainée dans l'ordre normal est la suivante: \n[ ");
        while(p!=NULL){
            printf("%d ",p->val);
            p=p->suiv;
        }
        printf("]\n");
    }
}
void printReverseDO(liste_double l){
    if(l==NULL){
        printf("Liste vide! Affichage impossible\n");
    }else{
        liste_double p=l;
        printf("La liste doublement chainée dans l'ordre  inverse est la suivante: \n[ ");
        while(p->suiv!=NULL){
            p=p->suiv;
        }
        while(p!=NULL){
            printf("%d ",p->val);
            p=p->preced;
        }
        printf("]\n");
    }
}