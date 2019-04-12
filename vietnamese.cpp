#include <QStringList>
#include <QString>
#include <QMap>
#include <QDebug>

typedef QMap<QString, QString> MapTableType;

static MapTableType w2p = {
    {"à", "af"},
    {"á", "as"},
    {"â", "aa"},
    {"ã", "ax"},
    {"è", "ef"},
    {"é", "es"},
    {"ê", "ee"},
    {"ì", "if"},
    {"í", "is"},
    {"ò", "of"},
    {"ó", "os"},
    {"ô", "oo"},
    {"õ", "ox"},
    {"ù", "uf"},
    {"ú", "us"},
    {"ý", "ys"},
    {"ă", "aw"},
    {"đ", "dd"},
    {"ĩ", "ix"},
    {"ũ", "ux"},
    {"ơ", "ow"},
    {"ư", "uw"},
    {"ạ", "aj"},
    {"ả", "ar"},
    {"ấ", "aas"},
    {"ầ", "aaf"},
    {"ẩ", "aar"},
    {"ẫ", "aax"},
    {"ậ", "aaj"},
    {"ắ", "aws"},
    {"ằ", "awf"},
    {"ẳ", "awr"},
    {"ẵ", "awx"},
    {"ặ", "awj"},
    {"ẹ", "ej"},
    {"ẻ", "er"},
    {"ẽ", "ex"},
    {"ế", "ees"},
    {"ề", "eef"},
    {"ể", "eer"},
    {"ễ", "eex"},
    {"ệ", "eej"},
    {"ỉ", "ir"},
    {"ị", "ij"},
    {"ọ", "oj"},
    {"ỏ", "or"},
    {"ố", "oos"},
    {"ồ", "oof"},
    {"ổ", "oor"},
    {"ỗ", "oox"},
    {"ộ", "ooj"},
    {"ớ", "ows"},
    {"ờ", "owf"},
    {"ở", "owr"},
    {"ỡ", "owx"},
    {"ợ", "owj"},
    {"ụ", "uj"},
    {"ủ", "ur"},
    {"ứ", "uws"},
    {"ừ", "uwf"},
    {"ử", "uwr"},
    {"ữ", "uwx"},
    {"ự", "uwj"},
    {"ỳ", "yf"},
    {"ỵ", "yj"},
    {"ỷ", "yr"},
    {"ỹ", "yx"}
};

static MapTableType p2w = {
    {"aa", "â"},
    {"aaf", "ầ"},
    {"aaj", "ậ"},
    {"aar", "ẩ"},
    {"aas", "ấ"},
    {"aax", "ẫ"},
    {"af", "à"},
    {"aj", "ạ"},
    {"ar", "ả"},
    {"as", "á"},
    {"aw", "ă"},
    {"awf", "ằ"},
    {"awj", "ặ"},
    {"awr", "ẳ"},
    {"aws", "ắ"},
    {"awx", "ẵ"},
    {"ax", "ã"},
    {"dd", "đ"},
    {"ee", "ê"},
    {"eef", "ề"},
    {"eej", "ệ"},
    {"eer", "ể"},
    {"ees", "ế"},
    {"eex", "ễ"},
    {"ef", "è"},
    {"ej", "ẹ"},
    {"er", "ẻ"},
    {"es", "é"},
    {"ex", "ẽ"},
    {"if", "ì"},
    {"ij", "ị"},
    {"ir", "ỉ"},
    {"is", "í"},
    {"ix", "ĩ"},
    {"of", "ò"},
    {"oj", "ọ"},
    {"oo", "ô"},
    {"oof", "ồ"},
    {"ooj", "ộ"},
    {"oor", "ổ"},
    {"oos", "ố"},
    {"oox", "ỗ"},
    {"or", "ỏ"},
    {"os", "ó"},
    {"ow", "ơ"},
    {"owf", "ờ"},
    {"owj", "ợ"},
    {"owr", "ở"},
    {"ows", "ớ"},
    {"owx", "ỡ"},
    {"ox", "õ"},
    {"uf", "ù"},
    {"uj", "ụ"},
    {"ur", "ủ"},
    {"us", "ú"},
    {"uw", "ư"},
    {"uwf", "ừ"},
    {"uwj", "ự"},
    {"uwr", "ử"},
    {"uws", "ứ"},
    {"uwx", "ữ"},
    {"ux", "ũ"},
    {"yf", "ỳ"},
    {"yj", "ỵ"},
    {"yr", "ỷ"},
    {"ys", "ý"},
    {"yx", "ỹ"}
};

//static QStringList rules_1 = {
//    "aàáảãạ",
//    "ăằắẳẵặ",
//    "âầấẩẫậ",
//    "eèéẻẽẹ",
//    "êềếểễệ",
//    "iìíỉĩị",
//    "oòóỏõọ",
//    "ôồốổỗộ",
//    "ơờớởỡợ",
//    "uùúủũụ",
//    "ưừứửữự",
//    "yỳýỷỹỵ"
//};

//static QStringList rules_2 = {
//    "awă",
//    "aaâ",
//    "eeê",
//    "ooô",
//    "owơ",
//    "uwư",
//    "ddđ"
//};

//static QString tones = "fsrxj";

//void createTable()
//{
//    for(auto words: rules_1)
//    {
//        QString original = words.at(0);
//        words = words.mid(1);
//        for(auto rule: rules_2)
//        {
//            if(original == QString(rule.at(2)))
//            {
//                original = rule.mid(0,2);
//                break;
//            }
//        }
//        int i=0;
//        for(auto word: words)
//        {
//            w2p[word] = original + tones.at(i);
//            i++;
//        }
//    }

//    for(auto rule: rules_2)
//    {
//        w2p[rule.at(2)] = rule.mid(0,2);
//    }

//    auto it = w2p.begin();
//    while (it != w2p.end()) {
//        p2w[it.value()] = it.key();
//        it++;
//    }
//}

/*
 * @brief: convert phone to word
 * ex: Vieejt Nam => Việt Nam
 */
QString phone2word(QString phone)
{
    QString word = "";
    int i = 0;
    MapTableType::iterator it;
    while (i < phone.length()) {
        it = p2w.find(phone.mid(i, 3));
        if(it != p2w.end())
        {
            word += it.value();
            i += 3;
        }
        else {
            it = p2w.find(phone.mid(i, 2));
            if(it != p2w.end())
            {
                word += it.value();
                i += 2;
            }
            else {
                word += phone.mid(i, 1);
                i += 1;
            }
        }
    }
    return word;
}

/*
 * @brief: convert word to phone
 * ex: Việt Nam => Vieejt Nam
 */
QString word2phone(QString word)
{
    QString phone = "";
    for(auto w: word)
    {
        auto it = w2p.find(QString(w));
        if(it != w2p.end())
        {
            phone += it.value();
        }
        else
        {
            phone += w;
        }
    }
    return phone;
}
