##
## Makefile for  in /home/barret_l/rendu/Initiation_IA/dante
## 
## Made by Ludovic BARRETEAU
## Login   <barret_l@epitech.net>
## 
## Started on  Sat May 21 11:01:41 2016 Ludovic BARRETEAU
## Last update Fri May 27 12:00:21 2016 Ludovic BARRETEAU
##

G_DIR		=	generateur

L_DIR		=	largeur

P_DIR		=	profondeur

T_DIR		=	tournoi

EXEC            =       $(G_DIR)/generateur

EXEC            =       $(L_DIR)/largeur

EXEC            =       $(P_DIR)/profondeur

EXEC            =       $(T_DIR)/tournoi

all:	$(EXEC)

$(EXEC):
	@(cd $(L_DIR) && $(MAKE))
	@(cd $(P_DIR) && $(MAKE))
	@(cd $(T_DIR) && $(MAKE))
	@(cd $(G_DIR) && $(MAKE))

clean:
	@(cd $(L_DIR) && $(MAKE) $@)
	@(cd $(P_DIR) && $(MAKE) $@)
	@(cd $(T_DIR) && $(MAKE) $@)
	@(cd $(G_DIR) && $(MAKE) $@)

fclean:
	@(cd $(L_DIR) && $(MAKE) $@)
	@(cd $(P_DIR) && $(MAKE) $@)
	@(cd $(T_DIR) && $(MAKE) $@)
	@(cd $(G_DIR) && $(MAKE) $@)


re:
	@(cd $(L_DIR) && $(MAKE) $@)
	@(cd $(P_DIR) && $(MAKE) $@)
	@(cd $(P_DIR) && $(MAKE) $@)
	@(cd $(G_DIR) && $(MAKE) $@)

