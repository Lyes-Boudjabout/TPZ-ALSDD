 /**--------------------------------------------------------**/
  /**       T r a n s l a t i o n   Z to C (Standard)        **/
  /**             By Pr. D.E ZEGOUR                          **/
  /**             E S I - Algier                             **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  /**--------------------------------------------------------**/
  /**                  TPZ 2023-2024 ALSDD                   **/
  /**     REALISED BY Lyes BOUDJABOUT and Samer KAMOUCHE     **/
  /**                       1CPC G10                         **/
  /**--------------------------------------------------------**/

  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h> 
  #include <string.h> 
  #include <unistd.h>

  #define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
  #define MAX(X, Y) (((X) > (Y)) ? (X) : (Y)) ;

  typedef int bool ;

  #define True 1
  #define False 0

  /** -Implementation- **\: BINARY SERACH TREE OF STRUCTURES**/

  /** Structures **/

  typedef struct Tib Type_Tib  ;
  typedef Type_Tib * Typestr_Tib ;
  typedef int Type1_Tib  ;
  typedef bool Type2_Tib  ;
  struct Tib
    {
      Type1_Tib Field1 ;
      Type2_Tib Field2 ;
    };

  Type1_Tib Struct1_Tib ( Typestr_Tib S)
    {
      return  S->Field1 ;
    }

  Type2_Tib Struct2_Tib ( Typestr_Tib S)
    {
      return  S->Field2 ;
    }

  void Ass_struct1_Tib ( Typestr_Tib S, Type1_Tib Val )
    {
       S->Field1 = Val ;
    }

  void Ass_struct2_Tib ( Typestr_Tib S, Type2_Tib Val )
    {
       S->Field2 = Val ;
    }


  /** Binary search trees **/

  typedef Typestr_Tib Typeelem_ATib   ;
  typedef struct Noeud_ATib * Pointer_ATib ;

  struct Noeud_ATib
    {
      Typeelem_ATib  Val ;
      Pointer_ATib Fg ;
      Pointer_ATib Fd ;
      Pointer_ATib Pere ;
     } ;

  Typeelem_ATib Node_value_ATib( Pointer_ATib P )
    { return P->Val;   }

  Pointer_ATib Lc_ATib( Pointer_ATib P)
    { return P->Fg ; }

  Pointer_ATib Rc_ATib( Pointer_ATib P)
    { return P->Fd ; }

  Pointer_ATib Parent_ATib( Pointer_ATib P)
    { return P->Pere ; }

  void Ass_node_val_ATib ( Pointer_ATib P, Typeelem_ATib Val)
    {
      Typeelem_ATib _Temp ;
      _Temp = malloc(sizeof(Type_Tib));
      /* Global assignment of structure */
      _Temp->Field1 = Val->Field1;
      _Temp->Field2 = Val->Field2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Ass_lc_ATib( Pointer_ATib P, Pointer_ATib Q)
    { P->Fg =  Q;  }

  void Ass_rc_ATib( Pointer_ATib P, Pointer_ATib Q)
    { P->Fd =  Q ; }

  void Ass_parent_ATib( Pointer_ATib P, Pointer_ATib Q)
    { P->Pere =  Q ; }

  void Allocate_node_ATib( Pointer_ATib *P)
    {
      *P = (struct Noeud_ATib *) malloc( sizeof( struct Noeud_ATib))   ;
      (*P)->Val = malloc(sizeof(Type_Tib));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Free_node_ATib( Pointer_ATib P)
    { free( P ) ; }


  /** -Implementation- **\: LIST Of INTEGERS**/

  /** Linked lists **/

  typedef int Typeelem_Li   ;
  typedef struct Maillon_Li * Pointer_Li ;

  struct Maillon_Li
    {
      Typeelem_Li  Val ;
      Pointer_Li Suiv ;
    } ;

  Pointer_Li Allocate_cell_Li (Pointer_Li *P)
    {
      *P = (struct Maillon_Li *) malloc( sizeof( struct Maillon_Li)) ;
      (*P)->Suiv = NULL;
    }

  void Ass_val_Li(Pointer_Li P, Typeelem_Li Val)
    {
      P->Val = Val ;
    }

  void Ass_adr_Li( Pointer_Li P,  Pointer_Li Q)
    {
      P->Suiv = Q ;
    }

  Pointer_Li Next_Li(  Pointer_Li P)
    { return( P->Suiv ) ;  }

  Typeelem_Li Cell_value_Li( Pointer_Li P)
    { return( P->Val) ; }

  void Free_Li ( Pointer_Li P)
    { free (P);}


  /** -Implementation- **\: STACK OF BINARY SERACH TREES OF STRUCTURES**/
  /** Stacks**/

  typedef Pointer_ATib Typeelem_PATib ;
  typedef struct Maillon_PATib * Pointer_PATib ;
  typedef   Pointer_PATib  Typepile_PATib  ;

  struct Maillon_PATib
    {
      Typeelem_PATib  Val ;
      Pointer_PATib Suiv ;
    } ;

  void Createstack_PATib( Pointer_PATib *P )
    { *P = NULL ; }

  bool Empty_stack_PATib ( Pointer_PATib P )
    { return  (P == NULL ); }

  void Push_PATib ( Pointer_PATib *P,  Typeelem_PATib Val )
    {
      Pointer_PATib Q;

      Q = (struct Maillon_PATib *) malloc( sizeof( struct Maillon_PATib))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Pop_PATib ( Pointer_PATib *P,  Typeelem_PATib *Val )
    {
      Pointer_PATib Sauv;

      if (! Empty_stack_PATib (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Stack is empty");
    }

  /** For temporary variables **/
  typedef Typestr_Tib Typeelem_V1Tib;
  typedef Typeelem_V1Tib Typetab_V1Tib[1];

   
  /** Variables of main program **/
  Pointer_ATib R1=NULL;
  Pointer_ATib R2=NULL;
  int N;
  int M;
  int I;
  int J;
  int Val;
  Pointer_Li Z=NULL;
  Pointer_Li X=NULL;
  Pointer_Li Y=NULL;

  /** Standard functions **/

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** creating a binary search tree **/

  void Create_bst_ATib ( Pointer_ATib *Arbre, Typetab_V1Tib Tab , int  N)
    {
      int I;
      Pointer_ATib P, Q ;

      /* Creation De La Racine */
      Allocate_node_ATib ( &P ) ;
      *Arbre = P ;
      Ass_node_val_ATib ( P , Tab[0] ) ;
      for(I=2;I<=N;++I)
        {
          P = *Arbre ;
          Q = *Arbre ;
          while ((  Tab[I-1]->Field1 != Struct1_Tib(Node_value_ATib ( P ) )) && ( Q != NULL ))
            {
              P = Q ;
              if ( Tab[I-1]->Field1 <  Struct1_Tib(Node_value_ATib ( P ) ))
                Q = Lc_ATib ( P );
              else Q = Rc_ATib ( P ) ;
            }
          if ( Tab[I-1]->Field1 == Struct1_Tib(Node_value_ATib ( P ) ))
            printf ("%s \n", "A double exists");
          else
            {
              Allocate_node_ATib ( &Q ) ;
              Ass_node_val_ATib ( Q , Tab[I-1] ) ;
              if ( Tab[I-1]->Field1 <  Struct1_Tib(Node_value_ATib ( P ) ))
                Ass_lc_ATib ( P , Q ) ;
              else Ass_rc_ATib ( P , Q );
              Ass_parent_ATib (Q, P);
            }
        }
    }


 /** Function prototypes **/

  void Branch_traversal (Pointer_ATib *P , Pointer_Li *L);
  void Inorder (Pointer_ATib *R , Pointer_Li *L);
  void Branch_traversal_no_check (Pointer_ATib *P , Pointer_Li *L);
  bool  Increasing_llc (Pointer_Li *L) ;
  void Insert_in_llc (Pointer_Li *L , int *Val);
  bool  Search_in_bst (Pointer_ATib *R , int *Val) ;
  void Insert_in_bst (Pointer_ATib *R , int *Val);
  bool  Two_llc_equality (Pointer_Li *L1 , Pointer_Li *L2) ;
  void Convert_to_not_visited (Pointer_ATib *P);
  void Delete_leaf (Pointer_ATib *L);
  void Eliminate_duplicates_list (Pointer_Li *L);
  void Display_list (Pointer_Li *L);
  void Bb_lr (Pointer_ATib *P , Pointer_Li *L);
  void Bb_rl (Pointer_ATib *P , Pointer_Li *L);
  void Ll_lr_second (Pointer_ATib *R , Pointer_Li *L);
  void Ll_lr (Pointer_ATib *P , Pointer_Li *L);
  void Ll_rl_second (Pointer_ATib *R , Pointer_Li *L);
  void Ll_rl (Pointer_ATib *P , Pointer_Li *L);
  void Verify_bb_lr (Pointer_ATib *P , Pointer_Li *L);
  void Verify_bb_rl (Pointer_ATib *P , Pointer_Li *L);
  void Verify_ll_lr_second (Pointer_ATib *R , Pointer_Li *L);
  void Verify_ll_lr (Pointer_ATib *R , Pointer_Li *L);
  void Verify_ll_rl_second (Pointer_ATib *R , Pointer_Li *L);
  void Verify_ll_rl (Pointer_ATib *R , Pointer_Li *L);

  /*---------------------------------- TOOLS ----------------------------------*/
  void Branch_traversal (Pointer_ATib *P , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib R=NULL;
      int _Px1;

      /** Body of function **/
     R  =  *P ;
     while( R != NULL)  {
       if( ( Struct2_Tib ( Node_value_ATib ( R )  ) == False )) {
         _Px1 =  Struct1_Tib ( Node_value_ATib ( R )  ) ;
         Insert_in_llc ( & *L , &_Px1) ;
         Ass_struct2_Tib ( Node_value_ATib ( R )  , True ) ;
        
       } ;
       R  =  Parent_ATib ( R ) ;
      
     }
    }
  /*---------------------------------------------------------------------------*/
  void Inorder (Pointer_ATib *R , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib _Px1=NULL;
      int _Px2;
      Pointer_ATib _Px3=NULL;

      /** Body of function **/
     if( ( *R != NULL )) {
       _Px1 =  Lc_ATib ( *R ) ;
       Inorder ( &_Px1, & *L ) ;
       _Px2 =  Struct1_Tib ( Node_value_ATib ( *R )  ) ;
       Insert_in_llc ( & *L , &_Px2) ;
       _Px3 =  Rc_ATib ( *R ) ;
       Inorder ( &_Px3, & *L ) ;
      
     }
    }
  /*---------------------------------------------------------------------------*/
  void Branch_traversal_no_check (Pointer_ATib *P , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib R=NULL;
      int _Px1;

      /** Body of function **/
     R  =  *P ;
     while( ( R != NULL )) {
       _Px1 =  Struct1_Tib ( Node_value_ATib ( R )  ) ;
       Insert_in_llc ( & *L , &_Px1) ;
       R  =  Parent_ATib ( R ) ;
      
     }
    }
  /*---------------------------------------------------------------------------*/
  bool  Increasing_llc (Pointer_Li *L)
    {
      /** Local variables **/
      bool  Increasing_llc2 ;
     Pointer_Li P=NULL;
      Pointer_Li Q=NULL;
      bool Stop;

      /** Body of function **/
     P  =  Next_Li ( *L ) ;
     Q  =  *L ;
     Stop  =  False ;
     while( ( P != NULL ) && ( ! Stop )) {
       if( ( Cell_value_Li ( P ) > Cell_value_Li ( Q ) )) {
         P  =  Next_Li ( P ) ;
         Q  =  Next_Li ( Q ) ;
         }
       else
         {
         Stop  =  True ;
        
       }
     } ;
     Increasing_llc2  =  ( ! Stop ) ;
    
     return Increasing_llc2 ;
    }
  /*---------------------------------------------------------------------------*/
  void Insert_in_llc (Pointer_Li *L , int *Val)
    {
      /** Local variables **/
      Pointer_Li P=NULL;
      Pointer_Li Q=NULL;

      /** Body of function **/
     Allocate_cell_Li (& Q ) ;
     Ass_val_Li ( Q , *Val ) ;
     Ass_adr_Li ( Q , NULL ) ;
     if( ( *L == NULL )) {
       *L  =  Q ;
       }
     else
       {
       P  =  *L ;
       while( ( Next_Li ( P ) != NULL )) {
         P  =  Next_Li ( P ) ;
        
       } ;
       Ass_adr_Li ( P , Q ) ;
      
     }
    }
  /*---------------------------------------------------------------------------*/
  bool  Search_in_bst (Pointer_ATib *R , int *Val)
    {
      /** Local variables **/
      bool  Search_in_bst2 ;
     Pointer_ATib _Px1=NULL;
      Pointer_ATib _Px2=NULL;

      /** Body of function **/
     if( ( *R == NULL )) {
       Search_in_bst2  =  False ;
       }
     else
       {
       if( ( Struct1_Tib ( Node_value_ATib ( *R )  ) == *Val )) {
         Search_in_bst2  =  True ;
         }
       else
         {
         if( ( Struct1_Tib ( Node_value_ATib ( *R )  ) > *Val )) {
           _Px1 =  Lc_ATib ( *R ) ;
           Search_in_bst2  =  Search_in_bst ( &_Px1, & *Val ) ;
           }
         else
           {
           _Px2 =  Rc_ATib ( *R ) ;
           Search_in_bst2  =  Search_in_bst ( &_Px2, & *Val ) ;
          
         }
       }
     }
     return Search_in_bst2 ;
    }
  /*---------------------------------------------------------------------------*/
  void Insert_in_bst (Pointer_ATib *R , int *Val)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_ATib Q=NULL;
      Pointer_ATib T=NULL;
      Pointer_PATib S=NULL;
      bool Found;
        Typetab_V1Tib T_Q;
      Type_Tib S_Q;
      int _Izw;  /** Variable de contrôle **/

      /** Body of function **/
     int _Izw2;for (_Izw2=0; _Izw2<1; ++_Izw2)
       T_Q[_Izw2] = malloc(sizeof(Type_Tib));
     Found  =  Search_in_bst ( & *R , & *Val ) ;
     if( ( ! Found )) {
       S_Q.Field1 = *Val ;
       S_Q.Field2 = False ;
       *T_Q [ 0 ] = S_Q ; 
       Create_bst_ATib (&Q , T_Q , 1 )  ;
       Ass_lc_ATib ( Q , NULL ) ;
       Ass_rc_ATib ( Q , NULL ) ;
       Createstack_PATib (& S ) ;
       if( ( *R == NULL )) {
         *R  =  Q ;
         Ass_parent_ATib ( *R , NULL ) ;
         }
       else
         {
         P  =  *R ;
         while( ( P != NULL )) {
           if( ( *Val > Struct1_Tib ( Node_value_ATib ( P )  ) )) {
             Push_PATib (& S , P ) ;
             P  =  Rc_ATib ( P ) ;
             }
           else
             {
             Push_PATib (& S , P ) ;
             P  =  Lc_ATib ( P ) ;
            
           }
         } ;
         Pop_PATib (& S , &P ) ;
         if( ( *Val > Struct1_Tib ( Node_value_ATib ( P )  ) )) {
           Ass_rc_ATib ( P , Q ) ;
           Ass_parent_ATib ( Q , P ) ;
           }
         else
           {
           Ass_lc_ATib ( P , Q ) ;
           Ass_parent_ATib ( Q , P ) ;
          
         }
       }
     }
    }
  /*---------------------------------------------------------------------------*/
  bool  Two_llc_equality (Pointer_Li *L1 , Pointer_Li *L2)
    {
      /** Local variables **/
      bool  Two_llc_equality2 ;
     Pointer_Li P=NULL;
      Pointer_Li Q=NULL;
      bool Continue;

      /** Body of function **/
     P  =  *L1 ;
     Q  =  *L2 ;
     Continue  =  True ;
     while( ( P != NULL ) && ( Q != NULL ) && ( Continue )) {
       if( ( Cell_value_Li ( P ) == Cell_value_Li ( Q ) )) {
         P  =  Next_Li ( P ) ;
         Q  =  Next_Li ( Q ) ;
         }
       else
         {
         Continue  =  False ;
        
       }
     } ;
     if( ( Q != NULL ) || ( P != NULL )) {
       Continue  =  False ;
      
     } ;
     Two_llc_equality2  =  Continue ;
    
     return Two_llc_equality2 ;
    }
  /*---------------------------------------------------------------------------*/
  void Convert_to_not_visited (Pointer_ATib *P)
    {
      /** Local variables **/
      Pointer_ATib _Px1=NULL;
      Pointer_ATib _Px2=NULL;

      /** Body of function **/
     if( *P != NULL)   {
       _Px1 =  Lc_ATib ( *P ) ;
       Convert_to_not_visited ( &_Px1) ;
       Ass_struct2_Tib ( Node_value_ATib ( *P )  , False ) ;
       _Px2 =  Rc_ATib ( *P ) ;
       Convert_to_not_visited ( &_Px2) ;
      
     }
    }
  /*---------------------------------------------------------------------------*/
  void Delete_leaf (Pointer_ATib *L)
    {
      /** Local variables **/
      Pointer_ATib R=NULL;

      /** Body of function **/
     R  =  Parent_ATib ( *L ) ;
     if( ( R == NULL )) {
       *L  =  NULL ;
       }
     else
       {
       if( ( Lc_ATib ( R ) != NULL )) {
         if( ( Rc_ATib ( R ) != NULL )) {
           if( ( Lc_ATib ( R ) == *L )) {
             Ass_lc_ATib ( R , NULL ) ;
            
           } ;
           if( ( Rc_ATib ( R ) == *L )) {
             Ass_rc_ATib ( R , NULL ) ;
            
           } }
         else
           {
           Ass_lc_ATib ( R , NULL ) ;
          
         } }
       else
         {
         if( ( Rc_ATib ( R ) != NULL )) {
           Ass_rc_ATib ( R , NULL ) ;
           }
         else
           {
           printf ( " %s", "THE ENTERED NODE IS NOT A LEAF" ) ;
          
         }
       }
     }
    }
  /*---------------------------------------------------------------------------*/
  void Eliminate_duplicates_list (Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_Li P=NULL;
      Pointer_Li Q=NULL;
      Pointer_Li T=NULL;
      int Val;

      /** Body of function **/
     T  =  *L ;
     while( ( T != NULL )) {
       Val  =  Cell_value_Li ( T ) ;
       P  =  *L ;
       Q  =  NULL ;
       while( ( P != NULL )) {
         if( ( Cell_value_Li ( P ) != Val )) {
           P  =  Next_Li ( P ) ;
           if( ( Q == NULL )) {
             Q  =  *L ;
             }
           else
             {
             Q  =  Next_Li ( Q ) ;
            
           } }
         else
           {
           if( ( P == T )) {
             P  =  Next_Li ( P ) ;
             if( ( Q == NULL )) {
               Q  =  *L ;
               }
             else
               {
               Q  =  Next_Li ( Q ) ;
              
             } }
           else
             {
             if( ( Q == NULL )) {
               *L  =  Next_Li ( *L ) ;
               Free_Li ( P ) ;
               P  =  *L ;
               }
             else
               {
               if( ( Next_Li ( P ) == NULL )) {
                 Ass_adr_Li ( Q , NULL ) ;
                 Free_Li ( P ) ;
                 P  =  NULL ;
                 }
               else
                 {
                 Ass_adr_Li ( Q , Next_Li ( P ) ) ;
                 Free_Li ( P ) ;
                 P  =  Next_Li ( Q ) ;
                
               }
             }
           }
         }
       } ;
       T  =  Next_Li ( T ) ;
      
     }
    }
  /*---------------------------------------------------------------------------*/
  void Display_list (Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_Li P=NULL;

      /** Body of function **/
     P  =  *L ;
     while( ( P != NULL )) {
       printf ( " %d", Cell_value_Li(P) ) ;
       P  =  Next_Li ( P ) ;
      
     }
    }
  /*---------------------- BRANCH BY BRANCH LEFT TO RIGHT ---------------------*/
  void Bb_lr (Pointer_ATib *P , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib R=NULL;
      Pointer_ATib _Px1=NULL;
      Pointer_ATib _Px2=NULL;

      /** Body of function **/
     R  =  *P ;
     if( ( R != NULL )) {
       if( ( Lc_ATib ( R ) == NULL ) && ( Rc_ATib ( R ) == NULL )) {
         Branch_traversal ( & R , & *L ) ;
         }
       else
         {
         if( ( Lc_ATib ( R ) != NULL )) {
           _Px1 =  Lc_ATib ( R ) ;
           Bb_lr ( &_Px1, & *L ) ;
          
         } ;
         if( ( Rc_ATib ( R ) != NULL )) {
           _Px2 =  Rc_ATib ( R ) ;
           Bb_lr ( &_Px2, & *L ) ;
          
         } ;
        
       }
     } ;
    
    }
  /*---------------------- BRANCH BY BRANCH RIGHT TO LEFT ---------------------*/
  void Bb_rl (Pointer_ATib *P , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib R=NULL;
      Pointer_ATib _Px1=NULL;
      Pointer_ATib _Px2=NULL;

      /** Body of function **/
     R  =  *P ;
     if( ( R != NULL )) {
       if( ( Lc_ATib ( R ) == NULL ) && ( Rc_ATib ( R ) == NULL )) {
         Branch_traversal ( & R , & *L ) ;
         }
       else
         {
         if( ( Rc_ATib ( R ) != NULL )) {
           _Px1 =  Rc_ATib ( R ) ;
           Bb_rl ( &_Px1, & *L ) ;
          
         } ;
         if( ( Lc_ATib ( R ) != NULL )) {
           _Px2 =  Lc_ATib ( R ) ;
           Bb_rl ( &_Px2, & *L ) ;
          
         } ;
        
       }
     } ;
    
    }
  /*---------------------- LEAF BY LEAF LEFT TO RIGHT -------------------------*/
  void Ll_lr_second (Pointer_ATib *R , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;
      Pointer_ATib _Px5=NULL;
      Pointer_ATib _Px6=NULL;

      /** Body of function **/
     P  =  *R ;
     if( ( P != NULL )) {
       if( ( Lc_ATib ( P ) == NULL ) && ( Rc_ATib ( P ) == NULL )) {
         _Px1 =  Struct1_Tib ( Node_value_ATib ( P )  ) ;
         Insert_in_llc ( & *L , &_Px1) ;
         Ass_struct2_Tib ( Node_value_ATib ( P )  , True ) ;
         }
       else
         {
         if( ( Lc_ATib ( P ) != NULL ) && ( Rc_ATib ( P ) != NULL )) {
           if( ( Struct2_Tib ( Node_value_ATib ( Lc_ATib ( P ) )  ) ) && ( Struct2_Tib ( Node_value_ATib ( Rc_ATib ( P ) )  ) )) {
             _Px2 =  Struct1_Tib ( Node_value_ATib ( P )  ) ;
             Insert_in_llc ( & *L , &_Px2) ;
             Ass_struct2_Tib ( Node_value_ATib ( P )  , True ) ;
            
           } ;
           }
         else
           {
           if( ( Lc_ATib ( P ) != NULL ) && ( Rc_ATib ( P ) == NULL )) {
             if( ( Struct2_Tib ( Node_value_ATib ( Lc_ATib ( P ) )  ) )) {
               _Px3 =  Struct1_Tib ( Node_value_ATib ( P )  ) ;
               Insert_in_llc ( & *L , &_Px3) ;
               Ass_struct2_Tib ( Node_value_ATib ( P )  , True ) ;
              
             }
           } ;
           if( ( Lc_ATib ( P ) == NULL ) && ( Rc_ATib ( P ) != NULL )) {
             if( ( Struct2_Tib ( Node_value_ATib ( Rc_ATib ( P ) )  ) )) {
               _Px4 =  Struct1_Tib ( Node_value_ATib ( P )  ) ;
               Insert_in_llc ( & *L , &_Px4) ;
               Ass_struct2_Tib ( Node_value_ATib ( P )  , True ) ;
              
             }
           } ;
          
         } ;
         if( ( Lc_ATib ( P ) != NULL )) {
           if( ( ! Struct2_Tib ( Node_value_ATib ( Lc_ATib ( P ) )  ) )) {
             _Px5 =  Lc_ATib ( P ) ;
             Ll_lr_second ( &_Px5, & *L ) ;
            
           } ;
          
         } ;
         if( ( Rc_ATib ( P ) != NULL )) {
           if( ( ! Struct2_Tib ( Node_value_ATib ( Rc_ATib ( P ) )  ) )) {
             _Px6 =  Rc_ATib ( P ) ;
             Ll_lr_second ( &_Px6, & *L ) ;
            
           } ;
          
         } ;
        
       }
     }
    }
  /*---------------------------------------------------------------------------*/
  void Ll_lr (Pointer_ATib *P , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib R=NULL;
      int Cpt;

      /** Body of function **/
     R  =  *P ;
     while( ( ! Struct2_Tib ( Node_value_ATib ( R )  ) )) {
       Ll_lr_second ( & R , & *L ) ;
      
     }
    }
  /*---------------------- LEAF BY LEAF RIGHT TO LEFT -------------------------*/
  void Ll_rl_second (Pointer_ATib *R , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;
      Pointer_ATib _Px5=NULL;
      Pointer_ATib _Px6=NULL;

      /** Body of function **/
     P  =  *R ;
     if( ( P != NULL )) {
       if( ( Lc_ATib ( P ) == NULL ) && ( Rc_ATib ( P ) == NULL )) {
         _Px1 =  Struct1_Tib ( Node_value_ATib ( P )  ) ;
         Insert_in_llc ( & *L , &_Px1) ;
         Ass_struct2_Tib ( Node_value_ATib ( P )  , True ) ;
         }
       else
         {
         if( ( Lc_ATib ( P ) != NULL ) && ( Rc_ATib ( P ) != NULL )) {
           if( ( Struct2_Tib ( Node_value_ATib ( Lc_ATib ( P ) )  ) ) && ( Struct2_Tib ( Node_value_ATib ( Rc_ATib ( P ) )  ) )) {
             _Px2 =  Struct1_Tib ( Node_value_ATib ( P )  ) ;
             Insert_in_llc ( & *L , &_Px2) ;
             Ass_struct2_Tib ( Node_value_ATib ( P )  , True ) ;
            
           } ;
           }
         else
           {
           if( ( Lc_ATib ( P ) != NULL ) && ( Rc_ATib ( P ) == NULL )) {
             if( ( Struct2_Tib ( Node_value_ATib ( Lc_ATib ( P ) )  ) )) {
               _Px3 =  Struct1_Tib ( Node_value_ATib ( P )  ) ;
               Insert_in_llc ( & *L , &_Px3) ;
               Ass_struct2_Tib ( Node_value_ATib ( P )  , True ) ;
              
             }
           } ;
           if( ( Lc_ATib ( P ) == NULL ) && ( Rc_ATib ( P ) != NULL )) {
             if( ( Struct2_Tib ( Node_value_ATib ( Rc_ATib ( P ) )  ) )) {
               _Px4 =  Struct1_Tib ( Node_value_ATib ( P )  ) ;
               Insert_in_llc ( & *L , &_Px4) ;
               Ass_struct2_Tib ( Node_value_ATib ( P )  , True ) ;
              
             }
           } ;
          
         } ;
         if( ( Rc_ATib ( P ) != NULL )) {
           if( ( ! Struct2_Tib ( Node_value_ATib ( Rc_ATib ( P ) )  ) )) {
             _Px5 =  Rc_ATib ( P ) ;
             Ll_rl_second ( &_Px5, & *L ) ;
            
           } ;
          
         } ;
         if( ( Lc_ATib ( P ) != NULL )) {
           if( ( ! Struct2_Tib ( Node_value_ATib ( Lc_ATib ( P ) )  ) )) {
             _Px6 =  Lc_ATib ( P ) ;
             Ll_rl_second ( &_Px6, & *L ) ;
            
           } ;
          
         } ;
        
       }
     }
    }
  /*---------------------------------------------------------------------------*/
  void Ll_rl (Pointer_ATib *P , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib R=NULL;

      /** Body of function **/
     R  =  *P ;
     while( ( ! Struct2_Tib ( Node_value_ATib ( R )  ) )) {
       Ll_rl_second ( & R , & *L ) ;
      
     }
    }
  /*----------------- VERIFY BRANCH BY BRANCH LEFT TO RIGHT -------------------*/
  void Verify_bb_lr (Pointer_ATib *P , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib R=NULL;
      Pointer_ATib _Px1=NULL;
      Pointer_ATib _Px2=NULL;

      /** Body of function **/
     R  =  *P ;
     if( ( R != NULL )) {
       if( ( Lc_ATib ( R ) == NULL ) && ( Rc_ATib ( R ) == NULL )) {
         Branch_traversal_no_check ( & R , & *L ) ;
         }
       else
         {
         if( ( Lc_ATib ( R ) != NULL )) {
           _Px1 =  Lc_ATib ( R ) ;
           Verify_bb_lr ( &_Px1, & *L ) ;
          
         } ;
         if( ( Rc_ATib ( R ) != NULL )) {
           _Px2 =  Rc_ATib ( R ) ;
           Verify_bb_lr ( &_Px2, & *L ) ;
          
         } ;
        
       }
     } ;
     Eliminate_duplicates_list ( & *L ) ;
    
    }
  /*----------------- VERIFY BRANCH BY BRANCH RIGHT TO LEFT -------------------*/
  void Verify_bb_rl (Pointer_ATib *P , Pointer_Li *L)
    {
      /** Local variables **/
      Pointer_ATib R=NULL;
      Pointer_ATib _Px1=NULL;
      Pointer_ATib _Px2=NULL;

      /** Body of function **/
     R  =  *P ;
     if( ( R != NULL )) {
       if( ( Lc_ATib ( R ) == NULL ) && ( Rc_ATib ( R ) == NULL )) {
         Branch_traversal_no_check ( & R , & *L ) ;
         }
       else
         {
         if( ( Rc_ATib ( R ) != NULL )) {
           _Px1 =  Rc_ATib ( R ) ;
           Verify_bb_rl ( &_Px1, & *L ) ;
          
         } ;
         if( ( Lc_ATib ( R ) != NULL )) {
           _Px2 =  Lc_ATib ( R ) ;
           Verify_bb_rl ( &_Px2, & *L ) ;
          
         } ;
        
       }
     } ;
     Eliminate_duplicates_list ( & *L ) ;
    
    }
  /*-------------------- VERIFY LEAF BY LEAF LEFT TO RIGHT --------------------*/
  void Verify_ll_lr_second (Pointer_ATib *R , Pointer_Li *L)
    {
      /** Local variables **/
      int _Px1;
      Pointer_ATib _Px2=NULL;
      Pointer_ATib _Px3=NULL;

      /** Body of function **/
     if( ( *R != NULL )) {
       if( ( Lc_ATib ( *R ) == NULL ) && ( Rc_ATib ( *R ) == NULL )) {
         _Px1 =  Struct1_Tib ( Node_value_ATib ( *R )  ) ;
         Insert_in_llc ( & *L , &_Px1) ;
         Delete_leaf ( & *R ) ;
         }
       else
         {
         if( ( Lc_ATib ( *R ) != NULL )) {
           _Px2 =  Lc_ATib ( *R ) ;
           Verify_ll_lr_second ( &_Px2, & *L ) ;
          
         } ;
         if( ( Rc_ATib ( *R ) != NULL )) {
           _Px3 =  Rc_ATib ( *R ) ;
           Verify_ll_lr_second ( &_Px3, & *L ) ;
          
         } ;
        
       }
     }
    }
  /*---------------------------------------------------------------------------*/
  void Verify_ll_lr (Pointer_ATib *R , Pointer_Li *L)
    {

      /** Body of function **/
     while( ( *R != NULL )) {
       Verify_ll_lr_second ( & *R , & *L ) ;
      
     }
    }
  /*-------------------- VERIFY LEAF BY LEAF RIGHT TO LEFT --------------------*/
  void Verify_ll_rl_second (Pointer_ATib *R , Pointer_Li *L)
    {
      /** Local variables **/
      int _Px1;
      Pointer_ATib _Px2=NULL;
      Pointer_ATib _Px3=NULL;

      /** Body of function **/
     if( ( *R != NULL )) {
       if( ( Lc_ATib ( *R ) == NULL ) && ( Rc_ATib ( *R ) == NULL )) {
         _Px1 =  Struct1_Tib ( Node_value_ATib ( *R )  ) ;
         Insert_in_llc ( & *L , &_Px1) ;
         Delete_leaf ( & *R ) ;
         }
       else
         {
         if( ( Rc_ATib ( *R ) != NULL )) {
           _Px2 =  Rc_ATib ( *R ) ;
           Verify_ll_rl_second ( &_Px2, & *L ) ;
          
         } ;
         if( ( Lc_ATib ( *R ) != NULL )) {
           _Px3 =  Lc_ATib ( *R ) ;
           Verify_ll_rl_second ( &_Px3, & *L ) ;
          
         } ;
        
       }
     }
    }
  /*---------------------------------------------------------------------------*/
  void Verify_ll_rl (Pointer_ATib *R , Pointer_Li *L)
    {

      /** Body of function **/
     while( ( *R != NULL )) {
       Verify_ll_rl_second ( & *R , & *L ) ;
      
     }
    }
  
  /** -Implementation- **\: BINARY SEARCH TREE OF STRUCTURES**/
#define MAX_HEIGHT 1000
int lside[MAX_HEIGHT];
int rside[MAX_HEIGHT];
#define INFINITY (1 << 20);
int gap = 3; // Gap between left and right nodes
int print_next;

// Structure for ASCII tree nodes
typedef struct asciinode_struct {
    struct asciinode_struct *left, *right;
    int edge_length;
    int height;
    int lablen;
    int parent_dir;
    char label[11];
} asciinode;

// Function prototypes
asciinode *build_ascii_tree_recursively(Pointer_ATib t);
asciinode *build_ascii_tree(Pointer_ATib t);
void free_ascii_tree(asciinode *node);
void compute_lside(asciinode *node, int x, int y);
void compute_rside(asciinode *node, int x, int y);
void compute_edge_long(asciinode *node);
void print_level(asciinode *node, int x, int level);
void print_ascii_tree(Pointer_ATib t);

// Function to create an empty tree
Pointer_ATib make_empty(Pointer_ATib t) {
    if (t != NULL) {
        make_empty(t->Fg);
        make_empty(t->Fd);
        Free_node_ATib(t);
    }
    return NULL;
}

// Function to insert a value into the BST
Pointer_ATib insert(Type1_Tib value1, Type2_Tib value2, Pointer_ATib t) {
    if (t == NULL) {
        Allocate_node_ATib(&t);
        Ass_struct1_Tib(t->Val, value1);
        Ass_struct2_Tib(t->Val, value2);
        t->Fg = t->Fd = NULL;
    } else {
        if (value1 < Struct1_Tib(t->Val))
            t->Fg = insert(value1, value2, t->Fg);
        else
            t->Fd = insert(value1, value2, t->Fd);
    }
    return t;
}

// Function to build the ASCII tree recursively
asciinode *build_ascii_tree_recursively(Pointer_ATib t) {
    asciinode *node;

    if (t == NULL)
        return NULL;

    node = malloc(sizeof(asciinode));
    node->left = build_ascii_tree_recursively(t->Fg);
    node->right = build_ascii_tree_recursively(t->Fd);

    if (node->left != NULL)
        node->left->parent_dir = -1;

    if (node->right != NULL)
        node->right->parent_dir = 1;

    sprintf(node->label, "%d", Struct1_Tib(t->Val));
    node->lablen = strlen(node->label);

    return node;
}

// Function to build the ASCII tree
asciinode *build_the_ascii_tree(Pointer_ATib t) {
    asciinode *node;
    if (t == NULL)
        return NULL;
    node = build_ascii_tree_recursively(t);
    node->parent_dir = 0;
    return node;
}

// Function to free all nodes of the given tree
void free_ascii_tree(asciinode *node) {
    if (node == NULL)
        return;
    free_ascii_tree(node->left);
    free_ascii_tree(node->right);
    free(node);
}

// Function to compute the left side of the tree
void compute_lside(asciinode *node, int x, int y) {
    int i, isleft;
    if (node == NULL)
        return;
    isleft = (node->parent_dir == -1);
    lside[y] = MIN(lside[y], x - ((node->lablen - isleft) / 2));
    if (node->left != NULL) {
        for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++) {
            lside[y + i] = MIN(lside[y + i], x - i);
        }
    }
    compute_lside(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    compute_lside(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

// Function to compute the right side of the tree
void compute_rside(asciinode *node, int x, int y) {
    int i, notleft;
    if (node == NULL)
        return;
    notleft = (node->parent_dir != -1);
    rside[y] = MAX(rside[y], x + ((node->lablen - notleft) / 2));
    if (node->right != NULL) {
        for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++) {
            rside[y + i] = MAX(rside[y + i], x + i);
        }
    }
    compute_rside(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    compute_rside(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

// Function to compute the edge lengths of the tree
void compute_edge_long(asciinode *node) {
    int h, hmin, i, delta;
    if (node == NULL)
        return;
    compute_edge_long(node->left);
    compute_edge_long(node->right);

    /* first fill in the edge_length of node */
    if (node->right == NULL && node->left == NULL) {
        node->edge_length = 0;
    } else {
        if (node->left != NULL) {
            for (i = 0; i < node->left->height && i < MAX_HEIGHT; i++) {
                rside[i] = -INFINITY;
            }
            compute_rside(node->left, 0, 0);
            hmin = node->left->height;
        } else {
            hmin = 0;
        }
        if (node->right != NULL) {
            for (i = 0; i < node->right->height && i < MAX_HEIGHT; i++) {
                lside[i] = INFINITY;
            }
            compute_lside(node->right, 0, 0);
            hmin = MIN(node->right->height, hmin);
        } else {
            hmin = 0;
        }
        delta = 4;
        for (i = 0; i < hmin; i++) {
            delta = MAX(delta, gap + 1 + rside[i] - lside[i]);
        }
        if (((node->left != NULL && node->left->height == 1) ||
             (node->right != NULL && node->right->height == 1)) && delta > 4) {
            delta--;
        }

        node->edge_length = ((delta + 1) / 2) - 1;
    }

    // Now fill in the height of node
    h = 1;
    if (node->left != NULL) {
        h = MAX(node->left->height + node->edge_length + 1, h);
    }
    if (node->right != NULL) {
        h = MAX(node->right->height + node->edge_length + 1, h);
    }
    node->height = h;
}

// Function to print a level of the tree
void print_level(asciinode *node, int x, int level) {
    int i, isleft;
    if (node == NULL)
        return;
    isleft = (node->parent_dir == -1);
    if (level == 0) {
        for (i = 0; i < (x - print_next - ((node->lablen - isleft) / 2)); i++) {
            printf(" ");
        }
        print_next += i;
        printf("%s", node->label);
        print_next += node->lablen;
    } else if (node->edge_length >= level) {
        if (node->left != NULL) {
            for (i = 0; i < (x - print_next - (level)); i++) {
                printf(" ");
            }
            print_next += i;
            printf("/");
            print_next++;
        }
        if (node->right != NULL) {
            for (i = 0; i < (x - print_next + (level)); i++) {
                printf(" ");
            }
            print_next += i;
            printf("\\");
            print_next++;
        }
    } else {
        print_level(node->left, x - node->edge_length - 1, level - node->edge_length - 1);
        print_level(node->right, x + node->edge_length + 1, level - node->edge_length - 1);
    }
}

// Function to print the ASCII tree
void print_ascii_tree(Pointer_ATib t) {
    asciinode *proot;
    int xmin, i;
    if (t == NULL)
        return;
    proot = build_the_ascii_tree(t);
    compute_edge_long(proot);
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++) {
        lside[i] = INFINITY;
    }
    compute_lside(proot, 0, 0);
    xmin = 0;
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++) {
        xmin = MIN(xmin, lside[i]);
    }
    for (i = 0; i < proot->height; i++) {
        print_next = 0;
        print_level(proot, -xmin, i);
        printf("\n");
    }
    if (proot->height >= MAX_HEIGHT) {
        printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
    }
    free_ascii_tree(proot);
}

  int main(int argc, char *argv[])
    {
     srand(time(NULL));
     printf("%s","ENTER THE NUMBER OF TREES TO CREATE: ");
     scanf ( " %d", &M ) ;
     for( I  =  1 ;I <=  M ; ++I){
       printf ( " %s", "TREE NUMBER " );
       printf ( " %d \n", I ) ;
       printf("%s","ENTER THE NUMBER OF THE NODES IN THE TREE: ");
       scanf ( " %d", &N ) ;
       for( J  =  1 ;J <=  N ; ++J){
         Val  =  Aleanombre(2000 ) ;
         Insert_in_bst ( & R1 , & Val ) ;
         Insert_in_bst ( & R2 , & Val ) ;
        
       } ;
       Inorder ( & R1 , & Z ) ;
       if( ( Increasing_llc ( & Z ) )) {
         printf ( " %s \n", "THE BINARY SEARCH TREE IS CREATED SUCCESSFULLY !" ) ;
         printf (" %s  \n", "HERE IS THE TREE: ");
         print_ascii_tree(R1);
        /*--------- BRANCH BY BRANCH LEFT TO RIGHT TRAVERSAL ---------*/
         Bb_lr ( & R1 , & Y ) ;
         Verify_bb_lr ( & R1 , & X ) ;
         if( ( Two_llc_equality ( & X , & Y ) )) {
           printf ( " %s \n", "BRANCH BY BRANCH LEFT TO RIGHT TRAVERSAL IS CORRECT" ) ;
           printf("THE TRAVERSAL: ");
           Display_list(&Y);
           printf("\n");
           }
         else
           {
           printf ( " %s \n", "BRANCH BY BRANCH LEFT TO RIGHT TRAVERSAL IS NOT CORRECT" ) ;
          
         } ;
         Y  =  NULL ;
         X  =  NULL ;
         Convert_to_not_visited ( & R1 ) ;
        /*--------- BRANCH BY BRANCH RIGHT TO LEFT TRAVERSAL ---------*/
         Bb_rl ( & R1 , & Y ) ;
         Verify_bb_rl ( & R1 , & X ) ;
         if( ( Two_llc_equality ( & X , & Y ) )) {
           printf ( " %s \n", "BRANCH BY BRANCH RIGHT TO LEFT TRAVERSAL IS CORRECT" ) ;
           printf("THE TRAVERSAL: ");
           Display_list(&Y);
           printf("\n");
           }
         else
           {
           printf ( " %s \n", "BRANCH BY BRANCH RIGHT TO LEFT TRAVERSAL IS NOT CORRECT" ) ;
          
         } ;
         X  =  NULL ;
         Y  =  NULL ;
         Convert_to_not_visited ( & R1 ) ;
        /*--------- LEAF BY LEAF LEFT TO RIGHT TRAVERSAL ---------*/
         Ll_lr ( & R1 , & X ) ;
         Verify_ll_lr ( & R1 , & Y ) ;
         if( ( Two_llc_equality ( & X , & Y ) )) {
           printf ( " %s \n", "LEAF BY LEAF LEFT TO RIGHT TRAVERSAL IS CORRECT" ) ;
           printf("THE TRAVERSAL: ");
           Display_list(&X);
           printf("\n");
           }
         else
           {
           printf ( " %s \n", "LEAF BY LEAF LEFT TO RIGHT TRAVERSAL IS NOT CORRECT" ) ;
          
         } ;
         X  =  NULL ;
         Y  =  NULL ;
        /*--------- LEAF BY LEAF RIGHT TO LEFT TRAVERSAL ---------*/
         Ll_rl ( & R2 , & X ) ;
         Verify_ll_rl ( & R2 , & Y ) ;
         if( ( Two_llc_equality ( & X , & Y ) )) {
           printf ( " %s \n", "LEAF BY LEAF RIGHT TO LEFT TRAVERSAL IS CORRECT" ) ;
           printf("THE TRAVERSAL: ");
           Display_list(&X);
           printf("\n");
           }
         else
           {
           printf ( " %s \n", "LEAF BY LEAF RIGHT TO LEFT TRAVERSAL IS NOT CORRECT" ) ;
          
         } ;
         }
       else
         {
         printf ( " %s \n", "THE BINARY SEARCH TREE IS NOT CREATED SUCCESSFULLY" ) ;
        
       } ;
       printf("------------------------------------------------------ \n");
       Z  =  NULL ;
       Y  =  NULL ;
       X  =  NULL ;
      
     }
   
      system("PAUSE");
      return 0;
    }