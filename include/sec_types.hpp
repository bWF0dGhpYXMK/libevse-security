// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#ifndef EVSE_SEC_TYPES_HPP
#define EVSE_SEC_TYPES_HPP

#include <memory>
#include <openssl/x509v3.h>

template <> class std::default_delete<X509> {
public:
    void operator()(X509* ptr) const {
        ::X509_free(ptr);
    }
};

template <> class std::default_delete<X509_STORE> {
public:
    void operator()(X509_STORE* ptr) const {
        ::X509_STORE_free(ptr);
    }
};

template <> class std::default_delete<X509_STORE_CTX> {
public:
    void operator()(X509_STORE_CTX* ptr) const {
        ::X509_STORE_CTX_free(ptr);
    }
};

template <> class std::default_delete<X509_REQ> {
public:
    void operator()(X509_REQ* ptr) const {
        ::X509_REQ_free(ptr);
    }
};

template <> class std::default_delete<EVP_PKEY> {
public:
    void operator()(EVP_PKEY* ptr) const {
        ::EVP_PKEY_free(ptr);
    }
};

template <> class std::default_delete<EVP_PKEY_CTX> {
public:
    void operator()(EVP_PKEY_CTX* ptr) const {
        ::EVP_PKEY_CTX_free(ptr);
    }
};

template <> class std::default_delete<BIO> {
public:
    void operator()(BIO* ptr) const {
        ::BIO_free(ptr);
    }
};

template <> class std::default_delete<FILE> {
public:
    void operator()(FILE* ptr) const {
        ::fclose(ptr);
    }
};

template <> class std::default_delete<EVP_MD_CTX> {
public:
    void operator()(EVP_MD_CTX* ptr) const {
        ::EVP_MD_CTX_destroy(ptr);
    }
};

template <> class std::default_delete<EVP_ENCODE_CTX> {
public:
    void operator()(EVP_ENCODE_CTX* ptr) const {
        ::EVP_ENCODE_CTX_free(ptr);
    }
};

namespace evse_security {

using X509_ptr = std::unique_ptr<X509>;
using X509_STORE_ptr = std::unique_ptr<X509_STORE>;
using X509_STORE_CTX_ptr = std::unique_ptr<X509_STORE_CTX>;
using X509_REQ_ptr = std::unique_ptr<X509_REQ>;
using EVP_PKEY_ptr = std::unique_ptr<EVP_PKEY>;
using EVP_PKEY_CTX_ptr = std::unique_ptr<EVP_PKEY_CTX>;
using BIO_ptr = std::unique_ptr<BIO>;
using FILE_ptr = std::unique_ptr<FILE>;
using EVP_MD_CTX_ptr = std::unique_ptr<EVP_MD_CTX>;
using EVP_ENCODE_CTX_ptr = std::unique_ptr<EVP_ENCODE_CTX>;

} // namespace evse_security

#endif
