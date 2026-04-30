#include <iostream>
#include "srchilite/sourcehighlight.h"
#include "srchilite/langmap.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "usage: tento <file>\n";
        return 1;
    }

    try {
        srchilite::SourceHighlight hl("esc.outlang");
        srchilite::LangMap langMap(DATADIR, "lang.map");

        std::string lang = langMap.getMappedFileNameFromFileName(argv[1]);
        if (lang.empty())
            lang = "txt.lang";

        hl.highlight(argv[1], "", lang);
    } catch (const std::exception &e) {
        std::cerr << "tento: " << e.what() << "\n";
        return 1;
    }

    return 0;
}

