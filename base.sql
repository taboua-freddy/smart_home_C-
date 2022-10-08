--------------------------------------------------------
--  Fichier créé - jeudi-janvier-17-2019   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table ADMIN
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."ADMIN" 
   (	"AUTORITE" VARCHAR2(20 BYTE), 
	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"COLUMN1" VARCHAR2(30 BYTE), 
	"MOTPASS" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ALIMENT
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."ALIMENT" 
   (	"ID" VARCHAR2(20 BYTE), 
	"POIDS" NUMBER, 
	"TYPE" VARCHAR2(20 BYTE), 
	"GENRE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CARTE_M
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."CARTE_M" 
   (	"ID" NUMBER, 
	"ID_CARTE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CHAMBRE
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."CHAMBRE" 
   (	"NUMDC" VARCHAR2(20 BYTE), 
	"NOMDC" VARCHAR2(20 BYTE), 
	"NBRLIT" VARCHAR2(20 BYTE), 
	"DISPO" VARCHAR2(20 BYTE), 
	"LUMI" VARCHAR2(20 BYTE), 
	"TMP" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FENETRE
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."FENETRE" 
   (	"ETAT" VARCHAR2(20 BYTE), 
	"REFERENCE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table HISTORIQUE
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."HISTORIQUE" 
   (	"ID_HIST" NUMBER, 
	"DATE_HIST" DATE, 
	"HEURE_HIST" VARCHAR2(20 BYTE), 
	"ID" NUMBER, 
	"ACTION" VARCHAR2(100 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table HISTORIQUE_LOGIN
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."HISTORIQUE_LOGIN" 
   (	"NOM" VARCHAR2(50 BYTE), 
	"DATTE" DATE
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table JARDINIER
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."JARDINIER" 
   (	"IDJARDINIER" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"EMAIL" VARCHAR2(20 BYTE), 
	"TELEPHONE" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MEMBRE
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."MEMBRE" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"MOTPASS" VARCHAR2(20 BYTE), 
	"EMAIL" VARCHAR2(30 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PLACE_PARKING
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."PLACE_PARKING" 
   (	"NUMERO_PLACE" NUMBER(4,0), 
	"ETAT" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PORTE
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."PORTE" 
   (	"ETAT" VARCHAR2(20 BYTE), 
	"REFERENCE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table RECETTE
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."RECETTE" 
   (	"NOMT" VARCHAR2(20 BYTE), 
	"T" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table SALLON
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."SALLON" 
   (	"IDS" VARCHAR2(20 BYTE), 
	"NMS" VARCHAR2(20 BYTE), 
	"NBRM" VARCHAR2(20 BYTE), 
	"LUMIN" VARCHAR2(20 BYTE), 
	"TMPE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table VEHICULE
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."VEHICULE" 
   (	"NUMERO_PLACE" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table VEHICULE_PROPRIETAIRE
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."VEHICULE_PROPRIETAIRE" 
   (	"MATRICULE" VARCHAR2(20 BYTE), 
	"ID" NUMBER, 
	"MARQUE" VARCHAR2(20 BYTE), 
	"NUMERO_PLACE" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ZONE
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."ZONE" 
   (	"IDZONE" NUMBER, 
	"ZONE" VARCHAR2(20 BYTE), 
	"NUMERO" NUMBER, 
	"TYPE" VARCHAR2(20 BYTE), 
	"ETAT" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ZONEF
--------------------------------------------------------

  CREATE TABLE "SYSTEM"."ZONEF" 
   (	"IDZ" VARCHAR2(20 BYTE), 
	"NOMZ" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into SYSTEM.ADMIN
SET DEFINE OFF;
Insert into SYSTEM.ADMIN (AUTORITE,ID,NOM,PRENOM,COLUMN1,MOTPASS) values ('admin','12',null,null,null,'111');
REM INSERTING into SYSTEM.ALIMENT
SET DEFINE OFF;
Insert into SYSTEM.ALIMENT (ID,POIDS,TYPE,GENRE) values ('4','-7','mmm','legume');
REM INSERTING into SYSTEM.CARTE_M
SET DEFINE OFF;
Insert into SYSTEM.CARTE_M (ID,ID_CARTE) values ('12',' 49 1A 77 00');
REM INSERTING into SYSTEM.CHAMBRE
SET DEFINE OFF;
Insert into SYSTEM.CHAMBRE (NUMDC,NOMDC,NBRLIT,DISPO,LUMI,TMP) values ('13','A6','2','disponnible','22','25');
Insert into SYSTEM.CHAMBRE (NUMDC,NOMDC,NBRLIT,DISPO,LUMI,TMP) values ('5','a2','2','disponnible','6','22');
Insert into SYSTEM.CHAMBRE (NUMDC,NOMDC,NBRLIT,DISPO,LUMI,TMP) values ('3','A5','2','disponnible','22','26');
REM INSERTING into SYSTEM.FENETRE
SET DEFINE OFF;
Insert into SYSTEM.FENETRE (ETAT,REFERENCE) values ('12','f1');
Insert into SYSTEM.FENETRE (ETAT,REFERENCE) values ('1','f2');
Insert into SYSTEM.FENETRE (ETAT,REFERENCE) values ('12','f3');
Insert into SYSTEM.FENETRE (ETAT,REFERENCE) values ('12','f4');
REM INSERTING into SYSTEM.HISTORIQUE
SET DEFINE OFF;
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('102',to_date('24/11/18','DD/MM/RR'),'20:15:56','12','attribut le numero place 2 ?? l''id 12');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('100',to_date('24/11/18','DD/MM/RR'),'01:47:43','12','fermeture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('101',to_date('24/11/18','DD/MM/RR'),'01:47:45','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('103',to_date('24/11/18','DD/MM/RR'),'20:17:25','12','supprimer le vehicule de matricule de la place2');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('104',to_date('24/11/18','DD/MM/RR'),'20:22:54','12','supprimer le vehicule de matricule  de la place 0');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('105',to_date('24/11/18','DD/MM/RR'),'20:26:53','12','attribut le numero place 2 ?? l''id 13');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('106',to_date('24/11/18','DD/MM/RR'),'20:32:12','12','attribut le numero place 2 ?? l''id 12');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('107',to_date('24/11/18','DD/MM/RR'),'20:34:05','12','attribut le numero place 1 ?? l''id 13');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('108',to_date('24/11/18','DD/MM/RR'),'20:37:37','12','supprimer le vehicule de matricule  de la place 0');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('109',to_date('24/11/18','DD/MM/RR'),'20:38:22','12','supprimer le vehicule de matricule  de la place 0');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('110',to_date('24/11/18','DD/MM/RR'),'20:45:06','12','supprimer le vehicule de matricule  de la place 0');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('111',to_date('24/11/18','DD/MM/RR'),'20:47:20','12','supprimer le vehicule de matricule 1 de la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('112',to_date('24/11/18','DD/MM/RR'),'20:55:12','12','supprimer le vehicule de matricule 145 de la place 6');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('113',to_date('24/11/18','DD/MM/RR'),'22:03:02','12','supprimer le vehicule de matricule 1 de la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('114',to_date('24/11/18','DD/MM/RR'),'22:24:19','12','supprimer le vehicule de matricule  de la place 0');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('115',to_date('24/11/18','DD/MM/RR'),'22:27:39','12','supprimer le vehicule de matricule 3 de la place 3');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('116',to_date('24/11/18','DD/MM/RR'),'22:29:37','12','attribut le numero place 2 vers l''id 13');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('117',to_date('24/11/18','DD/MM/RR'),'22:31:18','12','affecte un invite au numero de place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('118',to_date('24/11/18','DD/MM/RR'),'23:09:50','12','affecte un invite au numero de place 4');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('119',to_date('24/11/18','DD/MM/RR'),'23:09:52','12','affecte un invite au numero de place 5');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('120',to_date('24/11/18','DD/MM/RR'),'23:09:56','12','affecte un invite au numero de place 6');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('121',to_date('24/11/18','DD/MM/RR'),'23:46:45','12','fermeture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('122',to_date('27/11/18','DD/MM/RR'),'07:15:45','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('123',to_date('27/11/18','DD/MM/RR'),'07:15:47','12','fermeture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('124',to_date('27/11/18','DD/MM/RR'),'08:42:02','12','supprime tous les invites du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('125',to_date('27/11/18','DD/MM/RR'),'18:40:32','12','affecte un invite au numero de place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('126',to_date('27/11/18','DD/MM/RR'),'18:40:57','12','supprimer un invite du numero de place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('127',to_date('28/11/18','DD/MM/RR'),'13:37:28','12','a supprim?? le v??hicule de matricule 123me de la place 4');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('128',to_date('28/11/18','DD/MM/RR'),'13:49:10','12','a ajoute un nouveau vehicule a l''id 12 sur la place 2');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('129',to_date('28/11/18','DD/MM/RR'),'13:50:37','12','a ajoute un nouveau vehicule a l''id 12 sur la place 3');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('130',to_date('28/11/18','DD/MM/RR'),'13:51:36','12','a ajoute un nouveau vehicule a l''id 13 sur la place 8');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('131',to_date('28/11/18','DD/MM/RR'),'13:53:00','12','a ajoute un nouveau vehicule a l''id 14 sur la place 6');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('132',to_date('28/11/18','DD/MM/RR'),'13:53:37','12','a ajoute un nouveau vehicule a l''id 12 sur la place 5');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('133',to_date('28/11/18','DD/MM/RR'),'13:54:28','12','a ajoute un nouveau vehicule a l''id 14 sur la place 9');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('134',to_date('28/11/18','DD/MM/RR'),'13:54:52','12','a ajoute un nouveau vehicule a l''id 14 sur la place 15');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('135',to_date('28/11/18','DD/MM/RR'),'13:55:21','12','a ajoute un nouveau vehicule a l''id 12 sur la place 12');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('136',to_date('28/11/18','DD/MM/RR'),'13:57:36','12','a ajoute un nouveau vehicule a l''id 14 sur la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('137',to_date('28/11/18','DD/MM/RR'),'14:00:10','12','a ajoute un nouveau vehicule a l''id 13 sur la place 13');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('138',to_date('28/11/18','DD/MM/RR'),'14:00:49','12','a affecte un invite sur le num??ro de place 4');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('139',to_date('28/11/18','DD/MM/RR'),'14:02:15','12','attribut le numero place 2 a l''id 13');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('140',to_date('28/11/18','DD/MM/RR'),'14:03:03','12','a supprime un invite du numero de place 4');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('141',to_date('28/11/18','DD/MM/RR'),'14:03:10','12','a affecte un invite sur le num??ro de place 4');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('142',to_date('28/11/18','DD/MM/RR'),'14:03:55','12','a supprime tous les invites du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('143',to_date('28/11/18','DD/MM/RR'),'14:04:57','12','fermeture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('144',to_date('28/11/18','DD/MM/RR'),'14:04:59','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('145',to_date('28/11/18','DD/MM/RR'),'17:33:05','12','a affecte un invite sur le num??ro de place 4');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('146',to_date('28/11/18','DD/MM/RR'),'20:09:08','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('147',to_date('28/11/18','DD/MM/RR'),'20:09:12','12','fermeture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('148',to_date('29/11/18','DD/MM/RR'),'12:02:13','12','a supprime le vehicule de matricule 1232ME de la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('149',to_date('29/11/18','DD/MM/RR'),'12:05:28','12','fermeture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('150',to_date('29/11/18','DD/MM/RR'),'12:07:59','12','a supprime le vehicule de matricule 123ME de la place 2');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('151',to_date('29/11/18','DD/MM/RR'),'12:10:28','12','a ajoute un nouveau vehicule a l''id 12 sur la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('152',to_date('29/11/18','DD/MM/RR'),'12:10:56','12','a affecte un invite sur le num??ro de place 10');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('153',to_date('09/12/18','DD/MM/RR'),'01:48:32','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('154',to_date('09/12/18','DD/MM/RR'),'01:48:50','12','fermeture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('155',to_date('09/12/18','DD/MM/RR'),'18:58:57','14','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('156',to_date('15/12/18','DD/MM/RR'),'00:53:31','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('157',to_date('15/12/18','DD/MM/RR'),'00:53:41','12','fermeture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('158',to_date('15/12/18','DD/MM/RR'),'00:54:57','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('159',to_date('15/12/18','DD/MM/RR'),'00:55:59','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('160',to_date('15/12/18','DD/MM/RR'),'00:56:06','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('161',to_date('15/12/18','DD/MM/RR'),'01:00:47','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('162',to_date('15/12/18','DD/MM/RR'),'01:01:02','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('163',to_date('15/12/18','DD/MM/RR'),'01:05:44','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('164',to_date('15/12/18','DD/MM/RR'),'01:06:21','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('165',to_date('15/12/18','DD/MM/RR'),'15:42:41','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('166',to_date('15/12/18','DD/MM/RR'),'16:25:38','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('167',to_date('15/12/18','DD/MM/RR'),'16:26:12','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('168',to_date('15/12/18','DD/MM/RR'),'16:26:14','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('169',to_date('15/12/18','DD/MM/RR'),'16:26:15','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('170',to_date('15/12/18','DD/MM/RR'),'16:26:15','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('171',to_date('15/12/18','DD/MM/RR'),'16:26:16','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('172',to_date('15/12/18','DD/MM/RR'),'16:26:16','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('173',to_date('15/12/18','DD/MM/RR'),'16:26:17','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('174',to_date('15/12/18','DD/MM/RR'),'16:26:17','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('175',to_date('15/12/18','DD/MM/RR'),'16:26:17','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('176',to_date('15/12/18','DD/MM/RR'),'16:26:18','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('177',to_date('15/12/18','DD/MM/RR'),'16:26:18','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('178',to_date('15/12/18','DD/MM/RR'),'16:26:18','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('179',to_date('15/12/18','DD/MM/RR'),'16:26:18','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('180',to_date('15/12/18','DD/MM/RR'),'16:26:18','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('181',to_date('15/12/18','DD/MM/RR'),'16:26:19','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('182',to_date('15/12/18','DD/MM/RR'),'16:26:19','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('183',to_date('15/12/18','DD/MM/RR'),'16:26:19','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('184',to_date('15/12/18','DD/MM/RR'),'16:26:19','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('185',to_date('15/12/18','DD/MM/RR'),'16:26:19','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('186',to_date('15/12/18','DD/MM/RR'),'16:26:20','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('187',to_date('15/12/18','DD/MM/RR'),'16:26:20','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('188',to_date('15/12/18','DD/MM/RR'),'16:26:20','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('189',to_date('15/12/18','DD/MM/RR'),'16:26:21','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('190',to_date('15/12/18','DD/MM/RR'),'16:26:21','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('191',to_date('15/12/18','DD/MM/RR'),'16:26:21','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('192',to_date('15/12/18','DD/MM/RR'),'16:26:21','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('193',to_date('15/12/18','DD/MM/RR'),'16:26:21','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('194',to_date('15/12/18','DD/MM/RR'),'16:26:21','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('195',to_date('15/12/18','DD/MM/RR'),'16:26:22','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('196',to_date('15/12/18','DD/MM/RR'),'16:26:22','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('197',to_date('15/12/18','DD/MM/RR'),'16:26:22','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('198',to_date('15/12/18','DD/MM/RR'),'16:26:22','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('199',to_date('15/12/18','DD/MM/RR'),'16:26:22','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('200',to_date('15/12/18','DD/MM/RR'),'16:26:23','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('201',to_date('15/12/18','DD/MM/RR'),'16:26:23','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('202',to_date('15/12/18','DD/MM/RR'),'16:28:06','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('203',to_date('18/12/18','DD/MM/RR'),'23:17:40','14','a changer son nunmero de place de 6 vers 7');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('204',to_date('18/12/18','DD/MM/RR'),'23:21:42','14','a changer son nunmero de place de 15 vers 11');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('205',to_date('18/12/18','DD/MM/RR'),'23:45:06','14','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('206',to_date('18/12/18','DD/MM/RR'),'23:46:22','14','a ajoute un nouveau vehicule a l''id 1 sur la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('207',to_date('18/12/18','DD/MM/RR'),'23:46:47','14','a changer son nunmero de place de 1 vers 2');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('208',to_date('18/12/18','DD/MM/RR'),'23:53:16','14','a ajoute un nouveau vehicule a l''id 1 sur la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('209',to_date('18/12/18','DD/MM/RR'),'23:53:29','14','a changer son nunmero de place de 1 vers 3');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('210',to_date('18/12/18','DD/MM/RR'),'23:57:07','14','a ajoute un nouveau vehicule a l''id 1 sur la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('211',to_date('18/12/18','DD/MM/RR'),'23:57:13','14','a changer son nunmero de place de 1 vers 2');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('212',to_date('19/12/18','DD/MM/RR'),'00:24:43','14','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('213',to_date('19/12/18','DD/MM/RR'),'00:42:21','14','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('214',to_date('19/12/18','DD/MM/RR'),'19:25:35','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('215',to_date('20/12/18','DD/MM/RR'),'17:43:14','12','a ajoute un nouveau vehicule a l''id 1 sur la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('216',to_date('20/12/18','DD/MM/RR'),'17:44:09','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('217',to_date('21/12/18','DD/MM/RR'),'03:02:32','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('218',to_date('21/12/18','DD/MM/RR'),'03:02:32','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('219',to_date('21/12/18','DD/MM/RR'),'03:02:32','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('220',to_date('21/12/18','DD/MM/RR'),'03:02:55','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('221',to_date('21/12/18','DD/MM/RR'),'03:02:59','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('222',to_date('21/12/18','DD/MM/RR'),'03:03:03','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('223',to_date('21/12/18','DD/MM/RR'),'03:03:05','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('224',to_date('21/12/18','DD/MM/RR'),'03:03:14','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('225',to_date('21/12/18','DD/MM/RR'),'03:03:31','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('226',to_date('21/12/18','DD/MM/RR'),'03:03:35','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('227',to_date('21/12/18','DD/MM/RR'),'03:03:38','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('228',to_date('21/12/18','DD/MM/RR'),'03:03:40','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('229',to_date('21/12/18','DD/MM/RR'),'03:24:28','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('230',to_date('21/12/18','DD/MM/RR'),'03:24:54','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('231',to_date('21/12/18','DD/MM/RR'),'03:26:24','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('232',to_date('21/12/18','DD/MM/RR'),'03:26:43','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('233',to_date('21/12/18','DD/MM/RR'),'03:26:50','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('234',to_date('21/12/18','DD/MM/RR'),'04:29:53','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('235',to_date('21/12/18','DD/MM/RR'),'04:34:26','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('236',to_date('21/12/18','DD/MM/RR'),'04:37:47','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('237',to_date('21/12/18','DD/MM/RR'),'04:38:55','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('238',to_date('21/12/18','DD/MM/RR'),'04:39:06','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('239',to_date('21/12/18','DD/MM/RR'),'04:41:36','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('240',to_date('21/12/18','DD/MM/RR'),'04:41:44','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('241',to_date('21/12/18','DD/MM/RR'),'04:42:21','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('242',to_date('21/12/18','DD/MM/RR'),'04:43:38','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('243',to_date('21/12/18','DD/MM/RR'),'04:44:09','12','a changer son nunmero de place de 1 vers 3');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('244',to_date('30/12/18','DD/MM/RR'),'21:58:01','12','a supprime le vehicule de matricule  de la place 0');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('245',to_date('30/12/18','DD/MM/RR'),'21:58:14','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('246',to_date('30/12/18','DD/MM/RR'),'21:58:24','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('247',to_date('30/12/18','DD/MM/RR'),'21:58:57','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('248',to_date('31/12/18','DD/MM/RR'),'22:00:56','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('249',to_date('31/12/18','DD/MM/RR'),'22:59:59','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('250',to_date('31/12/18','DD/MM/RR'),'23:02:16','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('251',to_date('31/12/18','DD/MM/RR'),'23:02:27','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('252',to_date('31/12/18','DD/MM/RR'),'23:03:06','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('253',to_date('31/12/18','DD/MM/RR'),'23:03:14','14','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('254',to_date('03/01/19','DD/MM/RR'),'22:32:47','14','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('255',to_date('03/01/19','DD/MM/RR'),'22:49:21','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('256',to_date('04/01/19','DD/MM/RR'),'02:05:20','12','a affecte un invite sur le num??ro de place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('257',to_date('04/01/19','DD/MM/RR'),'02:05:42','12','a supprime un invite du numero de place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('258',to_date('04/01/19','DD/MM/RR'),'02:06:11','12','a supprime tous les invites du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('259',to_date('04/01/19','DD/MM/RR'),'02:06:52','12','a ajoute un nouveau vehicule a l''id 6 sur la place 6');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('260',to_date('04/01/19','DD/MM/RR'),'02:08:22','12','a ajoute un nouveau vehicule a l''id 1 sur la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('261',to_date('04/01/19','DD/MM/RR'),'02:09:12','12','a supprime le vehicule de matricule DFQQqs de la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('262',to_date('04/01/19','DD/MM/RR'),'02:09:47','12','a supprime le vehicule de matricule EDSDSD de la place 6');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('263',to_date('04/01/19','DD/MM/RR'),'02:10:22','12','a supprime le vehicule de matricule  de la place 0');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('264',to_date('04/01/19','DD/MM/RR'),'02:10:48','12','a changer son nunmero de place de 2 vers 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('265',to_date('04/01/19','DD/MM/RR'),'02:11:18','12','a changer son nunmero de place de 0 vers 2');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('266',to_date('04/01/19','DD/MM/RR'),'02:12:31','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('267',to_date('04/01/19','DD/MM/RR'),'02:13:10','12','a ajoute un nouveau vehicule a l''id 1 sur la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('268',to_date('04/01/19','DD/MM/RR'),'02:13:50','12','a supprime le vehicule de matricule 135po de la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('269',to_date('04/01/19','DD/MM/RR'),'02:14:07','12','a supprime le vehicule de matricule  de la place 0');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('270',to_date('04/01/19','DD/MM/RR'),'02:24:26','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('271',to_date('04/01/19','DD/MM/RR'),'02:24:43','12','a ajoute un nouveau vehicule a l''id 1 sur la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('272',to_date('04/01/19','DD/MM/RR'),'02:25:00','12','a ajoute un nouveau vehicule a l''id 4 sur la place 4');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('273',to_date('04/01/19','DD/MM/RR'),'02:25:14','12','a supprime le vehicule de matricule 12 de la place 1');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('274',to_date('04/01/19','DD/MM/RR'),'02:25:29','12','a supprime le vehicule de matricule 45 de la place 4');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('275',to_date('04/01/19','DD/MM/RR'),'02:51:53','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('276',to_date('04/01/19','DD/MM/RR'),'03:04:47','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('277',to_date('04/01/19','DD/MM/RR'),'10:05:07','12','a ajoute un nouveau vehicule a l''id 6 sur la place 6');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('278',to_date('04/01/19','DD/MM/RR'),'10:05:50','12','a changer son nunmero de place de 6 vers 7');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('279',to_date('04/01/19','DD/MM/RR'),'10:42:29','14','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('280',to_date('04/01/19','DD/MM/RR'),'10:42:29','14','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('281',to_date('04/01/19','DD/MM/RR'),'10:42:29','14','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('282',to_date('04/01/19','DD/MM/RR'),'10:43:25','12','ouverture du parking');
Insert into SYSTEM.HISTORIQUE (ID_HIST,DATE_HIST,HEURE_HIST,ID,ACTION) values ('283',to_date('04/01/19','DD/MM/RR'),'10:44:17','12','ouverture du parking');
REM INSERTING into SYSTEM.HISTORIQUE_LOGIN
SET DEFINE OFF;
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('14',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('15/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('16/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('16/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('16/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('16/01/19','DD/MM/RR'));
Insert into SYSTEM.HISTORIQUE_LOGIN (NOM,DATTE) values ('12',to_date('04/01/19','DD/MM/RR'));
REM INSERTING into SYSTEM.JARDINIER
SET DEFINE OFF;
Insert into SYSTEM.JARDINIER (IDJARDINIER,NOM,PRENOM,EMAIL,TELEPHONE) values ('17','mohamed',null,null,'0');
Insert into SYSTEM.JARDINIER (IDJARDINIER,NOM,PRENOM,EMAIL,TELEPHONE) values ('123','salah','mokrani','uihfh@hotmail.fr','55241524');
REM INSERTING into SYSTEM.MEMBRE
SET DEFINE OFF;
Insert into SYSTEM.MEMBRE (ID,NOM,PRENOM,MOTPASS,EMAIL) values ('12','DEMASS','Bernard','111','tabouaf@gmail.com');
Insert into SYSTEM.MEMBRE (ID,NOM,PRENOM,MOTPASS,EMAIL) values ('13','DUPOISSON','Jean','2222','tabouaf@gmail.com');
Insert into SYSTEM.MEMBRE (ID,NOM,PRENOM,MOTPASS,EMAIL) values ('14','DUBOIS','Julie','245','tabouaf@gmail.com');
Insert into SYSTEM.MEMBRE (ID,NOM,PRENOM,MOTPASS,EMAIL) values ('12356','ttt','hhh','bbb',null);
Insert into SYSTEM.MEMBRE (ID,NOM,PRENOM,MOTPASS,EMAIL) values ('1005','add','add','12','bbb');
Insert into SYSTEM.MEMBRE (ID,NOM,PRENOM,MOTPASS,EMAIL) values ('1006','omar','jmai','sdsds','tabouaf@gmail.com');
Insert into SYSTEM.MEMBRE (ID,NOM,PRENOM,MOTPASS,EMAIL) values ('1009','talla','brice','555','brice@gmail.com');
Insert into SYSTEM.MEMBRE (ID,NOM,PRENOM,MOTPASS,EMAIL) values ('1007','omar','jmai','222','tabouaf@gmail.com');
Insert into SYSTEM.MEMBRE (ID,NOM,PRENOM,MOTPASS,EMAIL) values ('1008','Mrx','111','ria','ria@gmail.com');
Insert into SYSTEM.MEMBRE (ID,NOM,PRENOM,MOTPASS,EMAIL) values ('1010','henry','heur','5555','henry@gmail.com');
REM INSERTING into SYSTEM.PLACE_PARKING
SET DEFINE OFF;
Insert into SYSTEM.PLACE_PARKING (NUMERO_PLACE,ETAT,TYPE) values ('3','libre','proprietaire');
Insert into SYSTEM.PLACE_PARKING (NUMERO_PLACE,ETAT,TYPE) values ('2','libre','invite');
Insert into SYSTEM.PLACE_PARKING (NUMERO_PLACE,ETAT,TYPE) values ('5','libre','invite');
Insert into SYSTEM.PLACE_PARKING (NUMERO_PLACE,ETAT,TYPE) values ('6','libre','invite');
Insert into SYSTEM.PLACE_PARKING (NUMERO_PLACE,ETAT,TYPE) values ('1','libre','invite');
Insert into SYSTEM.PLACE_PARKING (NUMERO_PLACE,ETAT,TYPE) values ('7','libre','invite');
Insert into SYSTEM.PLACE_PARKING (NUMERO_PLACE,ETAT,TYPE) values ('4','libre','proprietaire');
REM INSERTING into SYSTEM.PORTE
SET DEFINE OFF;
Insert into SYSTEM.PORTE (ETAT,REFERENCE) values ('12','p1');
Insert into SYSTEM.PORTE (ETAT,REFERENCE) values ('12','p2');
REM INSERTING into SYSTEM.RECETTE
SET DEFINE OFF;
Insert into SYSTEM.RECETTE (NOMT,T) values ('de','s');
REM INSERTING into SYSTEM.SALLON
SET DEFINE OFF;
Insert into SYSTEM.SALLON (IDS,NMS,NBRM,LUMIN,TMPE) values ('12','salon1','0','0','0');
Insert into SYSTEM.SALLON (IDS,NMS,NBRM,LUMIN,TMPE) values ('1234','salon 1','2','3','4');
REM INSERTING into SYSTEM.VEHICULE
SET DEFINE OFF;
Insert into SYSTEM.VEHICULE (NUMERO_PLACE) values ('3');
Insert into SYSTEM.VEHICULE (NUMERO_PLACE) values ('4');
REM INSERTING into SYSTEM.VEHICULE_PROPRIETAIRE
SET DEFINE OFF;
Insert into SYSTEM.VEHICULE_PROPRIETAIRE (MATRICULE,ID,MARQUE,NUMERO_PLACE) values ('125me','12','TOYOTA','3');
Insert into SYSTEM.VEHICULE_PROPRIETAIRE (MATRICULE,ID,MARQUE,NUMERO_PLACE) values ('145me','14','FIAT','4');
REM INSERTING into SYSTEM.ZONE
SET DEFINE OFF;
Insert into SYSTEM.ZONE (IDZONE,ZONE,NUMERO,TYPE,ETAT) values ('1','4','5','gason','mal');
Insert into SYSTEM.ZONE (IDZONE,ZONE,NUMERO,TYPE,ETAT) values ('14','45','4','gason','bien');
Insert into SYSTEM.ZONE (IDZONE,ZONE,NUMERO,TYPE,ETAT) values ('12','A5','13','fruit','mal');
REM INSERTING into SYSTEM.ZONEF
SET DEFINE OFF;
Insert into SYSTEM.ZONEF (IDZ,NOMZ) values ('1','legumes');
--------------------------------------------------------
--  Constraints for Table ADMIN
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."ADMIN" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ALIMENT
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."ALIMENT" ADD CONSTRAINT "ALIMENT_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SYSTEM"."ALIMENT" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CARTE_M
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."CARTE_M" MODIFY ("ID_CARTE" NOT NULL ENABLE);
  ALTER TABLE "SYSTEM"."CARTE_M" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CHAMBRE
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."CHAMBRE" MODIFY ("NUMDC" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table HISTORIQUE
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."HISTORIQUE" ADD CONSTRAINT "HISTORIQUE_PK" PRIMARY KEY ("ID_HIST")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SYSTEM"."HISTORIQUE" MODIFY ("ID_HIST" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MEMBRE
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."MEMBRE" ADD CONSTRAINT "PK_IDM" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table PLACE_PARKING
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."PLACE_PARKING" ADD CONSTRAINT "NP_PK" PRIMARY KEY ("NUMERO_PLACE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table RECETTE
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."RECETTE" ADD CONSTRAINT "NOM" PRIMARY KEY ("NOMT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SYSTEM"."RECETTE" MODIFY ("NOMT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table VEHICULE
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."VEHICULE" MODIFY ("NUMERO_PLACE" NOT NULL ENABLE);
  ALTER TABLE "SYSTEM"."VEHICULE" ADD CONSTRAINT "VEHICULE_PK" PRIMARY KEY ("NUMERO_PLACE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table VEHICULE_PROPRIETAIRE
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."VEHICULE_PROPRIETAIRE" MODIFY ("NUMERO_PLACE" NOT NULL ENABLE);
  ALTER TABLE "SYSTEM"."VEHICULE_PROPRIETAIRE" MODIFY ("ID" NOT NULL ENABLE);
  ALTER TABLE "SYSTEM"."VEHICULE_PROPRIETAIRE" ADD CONSTRAINT "PK_MATR" PRIMARY KEY ("MATRICULE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table ZONEF
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."ZONEF" ADD CONSTRAINT "IDZ" PRIMARY KEY ("IDZ")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "SYSTEM"."ZONEF" MODIFY ("IDZ" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table ADMIN
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."ADMIN" ADD CONSTRAINT "ADMIN_FK1" FOREIGN KEY ("ID")
	  REFERENCES "SYSTEM"."MEMBRE" ("ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table CARTE_M
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."CARTE_M" ADD CONSTRAINT "CARTE_M_FK1" FOREIGN KEY ("ID")
	  REFERENCES "SYSTEM"."MEMBRE" ("ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table HISTORIQUE
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."HISTORIQUE" ADD CONSTRAINT "HISTORIQUE_FK2" FOREIGN KEY ("ID")
	  REFERENCES "SYSTEM"."MEMBRE" ("ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table VEHICULE
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."VEHICULE" ADD CONSTRAINT "VEHICULE_FK1" FOREIGN KEY ("NUMERO_PLACE")
	  REFERENCES "SYSTEM"."PLACE_PARKING" ("NUMERO_PLACE") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table VEHICULE_PROPRIETAIRE
--------------------------------------------------------

  ALTER TABLE "SYSTEM"."VEHICULE_PROPRIETAIRE" ADD CONSTRAINT "VEHICULE_PROPRIETAIRE_FK1" FOREIGN KEY ("ID")
	  REFERENCES "SYSTEM"."MEMBRE" ("ID") ENABLE;
  ALTER TABLE "SYSTEM"."VEHICULE_PROPRIETAIRE" ADD CONSTRAINT "VEHICULE_PROPRIETAIRE_FK2" FOREIGN KEY ("NUMERO_PLACE")
	  REFERENCES "SYSTEM"."VEHICULE" ("NUMERO_PLACE") ENABLE;
