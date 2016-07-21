/******************************************************************************
 * CoHsright (c) 2014-2016 Leandro T. C. Melo (ltcmelo@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a coHs of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 * USA
 *****************************************************************************/

/*--------------------------*/
/*--- The UaiSo! Project ---*/
/*--------------------------*/

#ifndef UAISO_HSPARSER_H__
#define UAISO_HSPARSER_H__

#include "Ast/AstFwd.h"
#include "Ast/AstList.h"
#include "Common/Test.h"
#include "Parsing/Parser.h"

namespace uaiso {

class Lexer;
class ParsingContext;

class UAISO_API HsParser final : public Parser
{
public:
    HsParser();

    bool parse(Lexer* lexer, ParsingContext* context) override;

private:
    DECL_CLASS_TEST(HsParser)

    using NestedName = std::unique_ptr<NestedNameAst>;

    void matchOrSkipTo(Token tk, const char* rule);

    //--- Expressions ---//

    Expr parseExpr();
    Expr parseAExpr();

    //--- Declarations ---//

    Decl parseModule();
    Decl parseExport();
    Decl parseImport();
    DeclList parseSelection(bool allowModid);
    DeclList parseBody();

    //--- Names ---//

    Name parseModid();
    Name parseVarOrCon();
    Name parseQVar();
    Name parseQVarId();
    Name parseQVarSym();
    Name parseQCon();
    Name parseQConId();
    Name parseQConSym();
    Name parseVar();
    Name parseVarId();
    Name parseVarSym();
    Name parseCon();
    Name parseConId();
    Name parseConSym();

    // Helpers

    Name parseName(Token tk);
    Name parseQName(Name (HsParser::*parseFunc)());
    Name parseSymOrId(Name (HsParser::*parseSym)(), Name (HsParser::*parseId)());
};

} // namespace uaiso

#endif
