#include "header/f_prototypes.hpp"

static std::vector<std::vector<Case>> cases(8, std::vector<Case>(8));

Case *getCase(int x, int y){
    return &cases[x][y];
}

void initCases(bool isCaseValidOnly) {
    std::for_each(cases.begin(), cases.end(), [isCaseValidOnly](std::vector<Case>& row) {
        std::for_each(row.begin(), row.end(), [isCaseValidOnly](Case& c) {
            if(!isCaseValidOnly){
                c.piece = NULL;
            }
            c.isValid = false;
        });
    });
}

void drawCasesSelected(){
    if(getPieceSelected() != NULL){
        
        SDL_Rect rect;
        rect.w = rect.h =  CASE_SIZE;
        rect.x = BORDER_SIZE - 2 + getPieceSelected()->x * CASE_SIZE;
        rect.y = BORDER_SIZE - 2 + getPieceSelected()->y * CASE_SIZE;

		SDL_SetRenderDrawColor(getRenderer(),255,242,0,255);
		drawHollowRect(rect,3);
    }
}

void drawHollowRect(SDL_Rect rect, int thickness) {
    SDL_RenderDrawRect(getRenderer(), &rect);
    
    SDL_Rect tempRect = { rect.x, rect.y, rect.w, thickness };
    SDL_RenderFillRect(getRenderer(), &tempRect);
    
    tempRect = { rect.x, rect.y + rect.h - thickness, rect.w, thickness };
    SDL_RenderFillRect(getRenderer(), &tempRect);
    
    tempRect = { rect.x, rect.y + thickness, thickness, rect.h - thickness * 2 };
    SDL_RenderFillRect(getRenderer(), &tempRect);
    
    tempRect = { rect.x + rect.w - thickness, rect.y + thickness, thickness, rect.h - thickness * 2 };
    SDL_RenderFillRect(getRenderer(), &tempRect);
}

void drawCasesValid(){
    SDL_Rect rect;
    rect.w = rect.h =  CASE_SIZE;

    for(int i = 0; i< 8; i++){
        for(int j = 0; j < 8; j++){
            if(getCase(i,j)->isValid){
                rect.x = BORDER_SIZE - 2 + i * CASE_SIZE;
                rect.y = BORDER_SIZE - 2 + j * CASE_SIZE;
                SDL_SetRenderDrawColor(getRenderer(),255,0,0,255);
                SDL_RenderFillRect(getRenderer(), &rect);
            }
        }
    }
}