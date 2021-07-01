////////////////////////////////////////
//
// SigmaDev - Game Development and Multimedia Library
// Copyright (C) 2020-2021 Dawid Jakubowski (jakubowski.dawid@gmail.com)
//
// SigmaDev Library is licensed under MIT License (You can find it in the LICENSE file)
// Most recent version of the library is found on github repository: 
// https://github.com/Codedemens/SigmaDev/
// 
// 
// File: /impl/include/SigmaDev/Misc/Path.h
// Description:
// Additional Notes:

#ifndef SD_MISC_PATH_H
#define SD_MISC_PATH_H

#include <SigmaDev/Misc/Class.h>
#include <initializer_list>
#include <vector>
#include <string>
#include <list>

////////////////////////////////////////

/**
 * @brief SD_StringPath is class representing a path, in which ids are strings.
 *        Used in many contextes in SigmaDev Lib, mostly in (but not limited to) 
 *        Composite-Like classes.
 */
//TODO - SD_Class inheritance
class SD_StringPath : public SD_Class  {
public:
    SD_DECLARE_CLASS_H()
    /**
     * @brief Empty SD_StringPath
     */
    SD_StringPath();
    /**
     * @brief Initialize the SD_StringPath by passing the STD 
     *        initializer_list of std::strings
     * 
     * @param path initialier_list of std::strings
     */
    SD_StringPath(std::initializer_list<std::string> path);
    /**
     * @brief Initialize the SD_StringPath by passing STD
     *        list of std::string
     * 
     * @param path std::list of std::strings
     */
    SD_StringPath(const std::list<std::string>& path);
    /**
     * @brief Initialize the SD_StringPath by passing untokenized
     *        path - processes it using SD_StringPath::Process() method
     * 
     * @param path Untokenized path
     */
    SD_StringPath(const std::string& path);
    /**
     * @brief Copy Constructor. 
     * 
     * @param cpy Copy
     */
    SD_StringPath(const SD_StringPath& cpy);
    virtual ~SD_StringPath() = default;

    /**
     * @brief Compare two SD_StringPath s (every token must be the same,
     *        and the amount of tokens must be the same)
     * 
     * @param b Second SD_StringPath
     * @return true If they're the same
     * @return false If they're not the same
     */
    inline bool operator==(const SD_StringPath& b) const {
        const auto& list1 = path;
        const auto& list2 = b.GetTokenizedPath();
        if (list1.size() == list2.size()) {
            auto it1 = list1.begin();
            auto it2 = list2.begin();
            for( ; it1 != list1.end() && it2 != list2.end(); ++it1, ++it2) {
                const std::string& token1 = *it1;
                const std::string& token2 = *it2;

                if (token1.compare(token2) == 0) {
                    //Ok
                } else return false;
            }
        } else {
            return false;
        }
        return true;
    }
    inline bool operator<(const SD_StringPath& b) const {
        return untokenized < b.GetUntokenized();
    }
    /**
     * @brief Compare inequality of the two SD_StringPath s 
     * 
     * @param b Second SD_StringPath
     * @return true If they're not the same
     * @return false If they are same
     */
    inline bool operator!=(const SD_StringPath& b) const {
        return ! operator==(b);
    }

    inline const std::list<std::string>& GetTokenizedPath() const {
        return path;
    }
    inline const std::string& GetUntokenized() const {
        return untokenized;
    }
    inline void EraseBack() {
        path.pop_back();

    }
    inline void EraseFront() {
        path.pop_front();
    }
    inline const std::string& Back() const {
        return path.back();
    }
    inline const std::string& Front() const {
        return path.front();
    }
    inline bool IsEmpty() const {
        return path.empty();
    }
    inline std::size_t Size() const {
        return path.size();
    }
protected:
    /**
     * @brief Process the tokenized list of string IDS.
     *        Updates both the SD_StringPath::untokenized and SD_StringPath::path
     * 
     * @param tokenized 
     */
    virtual void Process(const std::list<std::string>& tokenized);
    /**
     * @brief Process the untokenized list of string IDS
     *        Updates both the SD_StringPath::untokenized and SD_StringPath::path
     * 
     * @param untokenized 
     */
    virtual void Process(const std::string& untokenized);

    std::list<std::string> path;
    std::string untokenized;
};

/**
 * @var SD_StringPath::path
 * @brief Tokenized path
 * 
 * @var SD_StringPath::untokenized
 * @brief Untokenized path
 * 
 */

////////////////////////////////////////

#endif