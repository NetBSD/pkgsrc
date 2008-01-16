# $NetBSD: product.mk,v 1.3 2008/01/16 14:54:41 taca Exp $
#

.if !defined(_ZOPE_PRODUCT_MK)
_ZOPE_PRODUCT_MK=	# defined

#
# ZOPE_PRODUCT_NAME
#	Zope extention (product) name.
#
# ZOPE_PKG_PRODUCT/ZOPE_PKG_PRODUCT_DIR
#	Basename/directory of Zope's extention package.
#
# ZOPE_PRODUCT_SRC
#	Source directory name relative to ${WRKSRC} of Zope's extention.
#
# ZOPE_PRODUCT_DST
#	Destination directory name of Zope's extention.
#

.include "../../www/zope/zopeversion.mk"

DEPENDS+=	${ZOPE_DEPENDENCY}

ZOPE_PKG_PRODUCT?=	${ZOPE_PRODUCTS_BASE}/${ZOPE_PRODUCT_NAME}
ZOPE_PKG_PRODUCT_DIR=	${ZOPE_PRODUCTS_DIR}/${ZOPE_PRODUCT_NAME}

ZOPE_PRODUCT_SRC?= .
ZOPE_PRODUCT_DST?= ${ZOPE_PRODUCT_NAME}

.if ${_ZOPE_VERSION} == "29"
_ZOPE_PRODUCT_DSTDIR= ${BUILDLINK_PREFIX.zope29}/${ZOPE_PKG_PRODUCT}
.elif ${_ZOPE_VERSION} == "210"
_ZOPE_PRODUCT_DSTDIR= ${BUILDLINK_PREFIX.zope210}/${ZOPE_PKG_PRODUCT}
.else
PKG_SKIP_REASON+=	"No valid Zope version"
.endif

ZOPE_PRODUCT_SRCDIR?= ${WRKSRC}/${ZOPE_PRODUCT_SRC}
ZOPE_PRODUCT_DSTDIR?= ${_ZOPE_PRODUCT_DSTDIR}

ZOPE_BYTE_COMPILE?=	yes
.if ${ZOPE_BYTE_COMPILE} == "yes" ||  ${ZOPE_BYTE_COMPILE} == "YES"
ZOPE_BUILD_METHOD?=	zope-simple-build
.else
ZOPE_BUILD_METHOD=	# empty
.endif

PLIST_SUBST+=	ZOPE_PRODUCT_NAME=${ZOPE_PRODUCT_NAME} \
		ZOPE_PKG_PRODUCT=${ZOPE_PKG_PRODUCT}

.if !target(do-build)
do-build: ${ZOPE_BUILD_METHOD}
	cd ${WRKSRC}; ${FIND} ${ZOPE_PRODUCT_SRC} -type f -print0 | \
		${XARGS} -0 -- ${CHMOD} a-w

zope-simple-build:
.for m in ${ZOPE_PRODUCT_SRC}
	cd ${WRKSRC}; ${PY_COMPILE_ALL} ${m}
.endfor

zope-force-build:
.for m in ${ZOPE_PRODUCT_SRC}
	cd ${WRKSRC}; ${PY_COMPILE_ALL} ${m} >/dev/null 2>&1 || ${TRUE}
.endfor

.endif

.PHONY: zope-install-product
zope-install-product:
	cd ${ZOPE_PRODUCT_SRCDIR:Q} && ${PAX} -rw \
		-s ',.*/CVS/.*,,'		\
		-s ',.*/CVS$$,,'		\
		-s ',.*/\.cvsignore$$,,' 	\
		-s ',.*\.orig$$,,'		\
		-s ',.*/\#.*,,'			\
		-s ',.*~$$,,'			\
		-s ',.*/.svn/.*,,'		\
		-s ',.*/\._.*,,'		\
		-s ',.*/.svn$$,,'		\
		-s ',svn-commit\.tmp,,'		\
		${ZOPE_PRODUCT_SRC} ${DESTDIR}${ZOPE_PRODUCT_DSTDIR}

.if !target(do-install)
do-install: zope-install-product
.endif

.include "../../lang/python/application.mk"
.endif
