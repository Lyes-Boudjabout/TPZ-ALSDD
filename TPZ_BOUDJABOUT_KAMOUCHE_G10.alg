
   LET
       LL_LR_second , LL_LR : ACTIONS ;
       LL_RL_second , LL_RL : ACTIONS ;
       BB_LR , BB_RL : ACTIONS ;
       ELIMINATE_DUPLICATES_LIST : ACTION ;
       VERIFY_BB_RL , VERIFY_BB_LR : ACTIONS ;
       VERIFY_LL_LR , VERIFY_LL_RL : ACTIONS ;
       VERIFY_LL_LR_second , VERIFY_LL_RL_second : ACTIONS ;
       DISPLAY_LIST  : ACTION ;
       CONVERT_TO_NOT_VISITED : ACTIONS ;
       GetBranch , INORDER , Branch_traversal_no_check : ACTION;
       INSERT_IN_LLC , SUP_LEAF : ACTION;
       INSERT_IN_BST : ACTION;
       TWO_LLC_EQUALITY , INCREASING_LLC , SEARCH_IN_BST : FUNCTION(BOOLEAN);
       R11 , R12 : BST OF ( INTEGER , BOOLEAN ) ;
       n , m , i , j , VAL : INTEGER ;
       Z , X , Y : LIST OF INTEGER ;
   BEGIN
      READ(m);
      FOR i:=1, m
        WRITE('TREE NUMBER ',i);
        READ(n);
        FOR j:=1, n
           VAL:=RANDNUMBER(2000);
           CALL INSERT_IN_BST(R11,VAL);
           CALL INSERT_IN_BST(R12,VAL);
        ENDFOR ;
        CALL INORDER(R11,Z);
        IF (INCREASING_LLC(Z))
           WRITE('THE BINARY SEARCH TREE IS CREATED SUCCESSFULLY !');

           {--------- BRANCH BY BRANCH LEFT TO RIGHT TRAVERSAL ---------}
           CALL BB_LR(R11,Y);
           CALL VERIFY_BB_LR(R11,X);
           IF (TWO_LLC_EQUALITY(X,Y))
              WRITE('BRANCH BY BRANCH LEFT TO RIGHT TRAVERSAL IS CORRECT');
           ELSE
              WRITE('BRANCH BY BRANCH LEFT TO RIGHT TRAVERSAL IS NOT CORRECT');
           ENDIF ;
           Y:=NULL;
           X:=NULL;
           CALL Convert_to_not_visited(R11);

           {--------- BRANCH BY BRANCH RIGHT TO LEFT TRAVERSAL ---------}
           CALL BB_RL(R11,Y);
           CALL VERIFY_BB_RL(R11,X);
           IF (TWO_LLC_EQUALITY(X,Y))
              WRITE('BRANCH BY BRANCH RIGHT TO LEFT TRAVERSAL IS CORRECT');
           ELSE
              WRITE('BRANCH BY BRANCH RIGHT TO LEFT TRAVERSAL IS NOT CORRECT');
           ENDIF;
           X:=NULL;
           Y:=NULL;
           CALL Convert_to_not_visited(R11);

           {--------- LEAF BY LEAF LEFT TO RIGHT TRAVERSAL ---------}
           CALL LL_LR(R11,X);
           CALL VERIFY_LL_LR(R11,Y);
           IF (TWO_LLC_EQUALITY(X,Y))
              WRITE('LEAF BY LEAF LEFT TO RIGHT TRAVERSAL IS CORRECT');
           ELSE
              WRITE('LEAF BY LEAF LEFT TO RIGHT TRAVERSAL IS NOT CORRECT');
           ENDIF ;
           X:=NULL;
           Y:=NULL;

           {--------- LEAF BY LEAF RIGHT TO LEFT TRAVERSAL ---------}
           CALL LL_RL(R12,X);
           CALL VERIFY_LL_RL(R12,Y);
           IF (TWO_LLC_EQUALITY(X,Y))
              WRITE('LEAF BY LEAF RIGHT TO LEFT TRAVERSAL IS CORRECT');
           ELSE
              WRITE('LEAF BY LEAF RIGHT TO LEFT TRAVERSAL IS NOT CORRECT');
           ENDIF ;
         ELSE
           WRITE('THE BINARY SEARCH TREE IS NOT CREATED SUCCESSFULLY');
         ENDIF;
        WRITE('--------------------------------------------');
        Z:=NULL;
        Y:=NULL;
        X:=NULL;
      ENDFOR
   END
   {---------------------------------- TOOLS ----------------------------------}
   ACTION GetBranch ( P , L )
   LET
       P , R : BST OF ( INTEGER , BOOLEAN ) ;
       L : LIST OF INTEGER ;
   BEGIN
       R:=P;
       WHILE R<>NULL :
           IF ( STRUCT(NODE_VALUE(R),2)=FALSE )
               CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(R),1));
               ASS_STRUCT(NODE_VALUE(R),2,TRUE) ;
           ENDIF ;
           R:=PARENT(R) ;
       ENDWHILE
   END
   {---------------------------------------------------------------------------}
   ACTION INORDER ( R , L )
   LET
      R : BST OF ( INTEGER , BOOLEAN ) ;
      L : LIST OF INTEGER ;
   DEBUT
      IF (R<>NULL)
         CALL INORDER(LC(R),L);
         CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(R),1));
         CALL INORDER(RC(R),L);
      ENDIF
   END
   {---------------------------------------------------------------------------}
   ACTION Branch_traversal_no_check ( P , L )
   LET
       P , R : BST OF ( INTEGER , BOOLEAN ) ;
       L : LIST OF INTEGER ;
   BEGIN
       R:=P;
       WHILE ( R<>NULL )
          CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(R),1));
          R:=PARENT(R);
       ENDWHILE
   END
   {---------------------------------------------------------------------------}
   FUNCTION INCREASING_LLC( L ):BOOLEAN;
   LET
      L , P , Q : LIST OF INTEGER ;
      STOP : BOOLEAN ;
   BEGIN
      P:=NEXT(L);
      Q:=L;
      STOP:=FALSE;
      WHILE (P<>NULL) AND (NOT STOP)
         IF (CELL_VALUE(P)>CELL_VALUE(Q))
            P:=NEXT(P);
            Q:=NEXT(Q);
         ELSE
            STOP:=TRUE;
         ENDIF
      ENDWHILE;
      INCREASING_LLC:=(NOT STOP);
   END
   {---------------------------------------------------------------------------}
   ACTION INSERT_IN_LLC (L,int)
   LET
      L , P , Q : LIST OF INTEGER ;
      int : INTEGER ;
   BEGIN
      ALLOCATE_CELL(Q);
      ASS_VAL(Q,int);
      ASS_ADR(Q,NULL);
      IF(L=NULL)
         L:=Q;
      ELSE
         P:=L;
         WHILE (NEXT(P)<>NULL)
            P:=NEXT(P);
         ENDWHILE;
         ASS_ADR(P,Q);
      ENDIF
   END
   {---------------------------------------------------------------------------}
   FUNCTION SEARCH_IN_BST ( R , INT ) : BOOLEAN ;
   LET
      R : BST OF ( INTEGER , BOOLEAN ) ;
      INT : INTEGER ;
   BEGIN
      IF (R=NULL)
         SEARCH_IN_BST:=FALSE;
      ELSE
         IF (STRUCT(NODE_VALUE(R),1)=INT)
            SEARCH_IN_BST:=TRUE;
         ELSE
            IF(STRUCT(NODE_VALUE(R),1)>INT)
               SEARCH_IN_BST:=SEARCH_IN_BST(LC(R),INT);
            ELSE
               SEARCH_IN_BST:=SEARCH_IN_BST(RC(R),INT);
            ENDIF
         ENDIF
      ENDIF
   END
   {---------------------------------------------------------------------------}
   ACTION INSERT_IN_BST(R,VAL)
   LET
      R , P , Q , T : BST OF ( INTEGER , BOOLEAN );
      S : STACK OF BST OF ( INTEGER , BOOLEAN );
      VAL : INTEGER ;
      FOUND : BOOLEAN ;
   BEGIN
      FOUND:=SEARCH_IN_BST(R,VAL);
      IF (NOT FOUND)
         CREATE_BST(Q,[[VAL,FALSE]]);
         ASS_LC(Q,NULL);
         ASS_RC(Q,NULL);
         CREATESTACK(S);
         IF(R=NULL)
            R:=Q;
            ASS_PARENT(R,NULL);
         ELSE
            P:=R;
            WHILE (P<>NULL)
               IF(VAL>STRUCT(NODE_VALUE(P),1))
                  PUSH(S,P);
                  P:=RC(P);
               ELSE
                  PUSH(S,P);
                  P:=LC(P);
               ENDIF
            ENDWHILE;
            POP(S,P);
            IF(VAL>STRUCT(NODE_VALUE(P),1))
               ASS_RC(P,Q);
               ASS_PARENT(Q,P);
            ELSE
               ASS_LC(P,Q);
               ASS_PARENT(Q,P);
            ENDIF
         ENDIF
      ENDIF
   END
   {---------------------------------------------------------------------------}
   FUNCTION TWO_LLC_EQUALITY ( L1 , L2 ) : BOOLEAN ;
   LET
      L1 , L2 , P , Q : LIST OF INTEGER ;
      CONTINUE : BOOLEAN ;
   BEGIN
      P:=L1;
      Q:=L2;
      CONTINUE:=TRUE;
      WHILE (P<>NULL) AND (Q<>NULL) AND (CONTINUE)
         IF (CELL_VALUE(P)=CELL_VALUE(Q))
            P:=NEXT(P);
            Q:=NEXT(Q);
         ELSE
            CONTINUE:=FALSE;
         ENDIF
      ENDWHILE;
      IF (Q<>NULL) OR (P<>NULL)
         CONTINUE:=FALSE;
      ENDIF;
      TWO_LLC_EQUALITY:=CONTINUE;
   END
   {---------------------------------------------------------------------------}
   ACTION CONVERT_TO_NOT_VISITED ( P )
   LET
       P : BST OF ( INTEGER , BOOLEAN ) ;
   BEGIN
       IF P <> NULL :
           CALL Convert_to_not_visited ( LC ( P ) ) ;
           ASS_STRUCT ( NODE_VALUE ( P ) , 2 , FALSE ) ;
           CALL Convert_to_not_visited ( RC ( P ) ) ;
       ENDIF
   END
   {---------------------------------------------------------------------------}
   ACTION SUP_LEAF(L)
   LET
      R , L : BST OF ( INTEGER , BOOLEAN );
   BEGIN
     R:=PARENT(L);
     IF (R=NULL)
        L:=NULL;
     ELSE
        IF (LC(R)<>NULL)
           IF (RC(R)<>NULL)
              IF (LC(R)=L)
                 ASS_LC(R,NULL);
              ENDIF;
              IF (RC(R)=L)
                 ASS_RC(R,NULL);
              ENDIF
           ELSE
              ASS_LC(R,NULL);
           ENDIF
        ELSE
           IF (RC(R)<>NULL)
              ASS_RC(R,NULL);
           ELSE
              WRITE('THE ENTERED NODE IS NOT A LEAF');
           ENDIF
        ENDIF
     ENDIF
   END
   {---------------------------------------------------------------------------}
   ACTION ELIMINATE_DUPLICATES_LIST (L)
   LET
      L , P , Q , T : LIST OF INTEGER ;
      VAL : INTEGER ;
   BEGIN
      T:=L;
      WHILE (T<>NULL)
         VAL:=CELL_VALUE(T);
         P:=L;
         Q:=NULL;
         WHILE (P<>NULL)
            IF ( CELL_VALUE(P)<>VAL )
               P:=NEXT(P);
               IF(Q=NULL)
                  Q:=L;
               ELSE
                  Q:=NEXT(Q);
               ENDIF
            ELSE
               IF (P=T)
                  P:=NEXT(P);
                  IF (Q=NULL)
                     Q:=L;
                  ELSE
                     Q:=NEXT(Q);
                  ENDIF
               ELSE
                  IF (Q=NULL)
                     L:=NEXT(L);
                     FREE(P);
                     P:=L;
                  ELSE
                     IF (NEXT(P)=NULL)
                        ASS_ADR(Q,NULL);
                        FREE(P);
                        P:=NULL;
                     ELSE
                        ASS_ADR(Q,NEXT(P));
                        FREE(P);
                        P:=NEXT(Q);
                     ENDIF
                  ENDIF
               ENDIF
            ENDIF
         ENDWHILE;
         T:=NEXT(T);
      ENDWHILE
   END
   {---------------------------------------------------------------------------}
   ACTION DISPLAY_LIST (L);
   LET
      L , P : LIST OF INTEGER;
   BEGIN
      P:=L;
      WHILE(P<>NULL)
         WRITE(CELL_VALUE(P));
         P:=NEXT(P);
      ENDWHILE
   END
   {---------------------- BRANCH BY BRANCH LEFT TO RIGHT ---------------------}
   ACTION BB_LR ( P , L )
   LET
      R , P : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER ;
   BEGIN
      R:=P;
      IF (R<>NULL)
         IF (LC(R)=NULL) AND (RC(R)=NULL)
            CALL GetBranch(R,L);
         ELSE
            IF (LC(R)<>NULL)
               CALL BB_LR(LC(R),L);
            ENDIF;
            IF (RC(R)<>NULL)
               CALL BB_LR(RC(R),L);
            ENDIF;
         ENDIF
      ENDIF;
   END
   {---------------------- BRANCH BY BRANCH RIGHT TO LEFT ---------------------}
   ACTION BB_RL ( P , L )
   LET
      R , P : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER ;
   BEGIN
      R:=P;
      IF (R<>NULL)
         IF (LC(R)=NULL) AND (RC(R)=NULL)
            CALL GetBranch(R,L);
         ELSE
            IF (RC(R)<>NULL)
               CALL BB_RL(RC(R),L);
            ENDIF;
            IF (LC(R)<>NULL)
               CALL BB_RL(LC(R),L);
            ENDIF;
         ENDIF
      ENDIF;
   END
   {---------------------- LEAF BY LEAF LEFT TO RIGHT -------------------------}
   ACTION LL_LR_second ( R , L )
   LET
      P , R : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER;
   BEGIN
      P:=R;
      IF (P<>NULL)
         IF (LC(P)=NULL) AND (RC(P)=NULL)
            CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(P),1));
            ASS_STRUCT(NODE_VALUE(P),2,TRUE);
         ELSE
            IF (LC(P)<>NULL) AND (RC(P)<>NULL)
               IF (STRUCT(NODE_VALUE(LC(P)),2)) AND (STRUCT(NODE_VALUE(RC(P)),2))
                  CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(P),1));
                  ASS_STRUCT(NODE_VALUE(P),2,TRUE);
               ENDIF;
            ELSE
               IF(LC(P)<>NULL) AND (RC(P)=NULL)
                  IF (STRUCT(NODE_VALUE(LC(P)),2))
                     CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(P),1));
                     ASS_STRUCT(NODE_VALUE(P),2,TRUE);
                  ENDIF
               ENDIF;
               IF(LC(P)=NULL) AND (RC(P)<>NULL)
                  IF (STRUCT(NODE_VALUE(RC(P)),2))
                     CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(P),1));
                     ASS_STRUCT(NODE_VALUE(P),2,TRUE);
                  ENDIF
               ENDIF;
            ENDIF  ;
            IF (LC(P)<>NULL)
               IF (NOT STRUCT(NODE_VALUE(LC(P)),2))
                  CALL LL_LR_second(LC(P),L);
               ENDIF ;
            ENDIF ;
            IF (RC(P)<>NULL)
               IF (NOT STRUCT(NODE_VALUE(RC(P)),2))
                  CALL LL_LR_second(RC(P),L);
               ENDIF ;
            ENDIF;
         ENDIF
      ENDIF
   END
   {---------------------------------------------------------------------------}
   ACTION LL_LR ( P , L )
   LET
      P , R : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER ;
      CPT : INTEGER ;
   BEGIN
      R:=P;
      WHILE (NOT STRUCT(NODE_VALUE(R),2))
         CALL LL_LR_second (R,L);
      ENDWHILE
   END
   {---------------------- LEAF BY LEAF RIGHT TO LEFT -------------------------}
   ACTION LL_RL_second ( R , L )
   LET
      P , R : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER;
   BEGIN
      P:=R;
      IF (P<>NULL)
         IF (LC(P)=NULL) AND (RC(P)=NULL)
            CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(P),1));
            ASS_STRUCT(NODE_VALUE(P),2,TRUE);
         ELSE
            IF (LC(P)<>NULL) AND (RC(P)<>NULL)
               IF (STRUCT(NODE_VALUE(LC(P)),2)) AND (STRUCT(NODE_VALUE(RC(P)),2))
                  CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(P),1));
                  ASS_STRUCT(NODE_VALUE(P),2,TRUE);
               ENDIF;
            ELSE
               IF(LC(P)<>NULL) AND (RC(P)=NULL)
                  IF (STRUCT(NODE_VALUE(LC(P)),2))
                     CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(P),1));
                     ASS_STRUCT(NODE_VALUE(P),2,TRUE);
                  ENDIF
               ENDIF;
               IF(LC(P)=NULL) AND (RC(P)<>NULL)
                  IF (STRUCT(NODE_VALUE(RC(P)),2))
                     CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(P),1));
                     ASS_STRUCT(NODE_VALUE(P),2,TRUE);
                  ENDIF
               ENDIF;
            ENDIF  ;
            IF (RC(P)<>NULL)
               IF (NOT STRUCT(NODE_VALUE(RC(P)),2))
                  CALL LL_RL_second(RC(P),L);
               ENDIF ;
            ENDIF ;
            IF (LC(P)<>NULL)
               IF (NOT STRUCT(NODE_VALUE(LC(P)),2))
                  CALL LL_RL_second(LC(P),L);
               ENDIF ;
            ENDIF;
         ENDIF
      ENDIF
   END
   {---------------------------------------------------------------------------}
   ACTION LL_RL ( P , L )
   LET
      P,R : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER ;
   BEGIN
      R:=P;
      WHILE (NOT STRUCT(NODE_VALUE(R),2))
         CALL LL_RL_second (R,L);
      ENDWHILE
   END
   {----------------- VERIFY BRANCH BY BRANCH LEFT TO RIGHT -------------------}
   ACTION VERIFY_BB_LR ( P , L )
   LET
      R , P : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER ;
   BEGIN
      R:=P;
      IF (R<>NULL)
         IF (LC(R)=NULL) AND (RC(R)=NULL)
            CALL Branch_Traversal_no_check(R,L);
         ELSE
            IF (LC(R)<>NULL)
               CALL VERIFY_BB_LR(LC(R),L);
            ENDIF;
            IF (RC(R)<>NULL)
               CALL VERIFY_BB_LR(RC(R),L);
            ENDIF;
         ENDIF
      ENDIF;
      CALL ELIMINATE_DUPLICATES_LIST(L);
   END
   {----------------- VERIFY BRANCH BY BRANCH RIGHT TO LEFT -------------------}
   ACTION VERIFY_BB_RL ( P , L )
   LET
      R , P : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER ;
   BEGIN
      R:=P;
      IF (R<>NULL)
         IF (LC(R)=NULL) AND (RC(R)=NULL)
            CALL Branch_Traversal_no_check(R,L);
         ELSE
            IF (RC(R)<>NULL)
               CALL VERIFY_BB_RL(RC(R),L);
            ENDIF;
            IF (LC(R)<>NULL)
               CALL VERIFY_BB_RL(LC(R),L);
            ENDIF;
         ENDIF
      ENDIF;
      CALL ELIMINATE_DUPLICATES_LIST(L);
   END
   {-------------------- VERIFY LEAF BY LEAF LEFT TO RIGHT --------------------}
   ACTION VERIFY_LL_LR_second ( R , L )
   LET
      R : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER ;
   BEGIN
      IF (R<>NULL)
         IF (LC(R)=NULL) AND (RC(R)=NULL)
            CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(R),1));
            CALL SUP_LEAF(R);
         ELSE
            IF(LC(R)<>NULL)
               CALL VERIFY_LL_LR_second(LC(R),L);
            ENDIF;
            IF(RC(R)<>NULL)
               CALL VERIFY_LL_LR_second(RC(R),L);
            ENDIF;
         ENDIF
      ENDIF
   END
   {---------------------------------------------------------------------------}
   ACTION VERIFY_LL_LR ( R , L )
   LET
      R : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER ;
   BEGIN
      WHILE(R<>NULL)
         CALL VERIFY_LL_LR_second ( R , L );
      ENDWHILE
   END
   {-------------------- VERIFY LEAF BY LEAF RIGHT TO LEFT --------------------}
   ACTION VERIFY_LL_RL_second ( R , L )
   LET
      R : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER ;
   BEGIN
      IF (R<>NULL)
         IF (LC(R)=NULL) AND (RC(R)=NULL)
            CALL INSERT_IN_LLC(L,STRUCT(NODE_VALUE(R),1));
            CALL SUP_LEAF(R);
         ELSE
            IF(RC(R)<>NULL)
               CALL VERIFY_LL_RL_second(RC(R),L);
            ENDIF;
            IF(LC(R)<>NULL)
               CALL VERIFY_LL_RL_second(LC(R),L);
            ENDIF;
         ENDIF
      ENDIF
   END
   {---------------------------------------------------------------------------}
   ACTION VERIFY_LL_RL ( R , L )
   LET
      R : BST OF ( INTEGER , BOOLEAN );
      L : LIST OF INTEGER ;
   BEGIN
      WHILE(R<>NULL)
         CALL VERIFY_LL_RL_second ( R , L );
      ENDWHILE
   END
   {---------------------------------------------------------------------------}


































