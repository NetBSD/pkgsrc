# $NetBSD: options.mk,v 1.1 2015/04/19 23:10:52 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.serd
PKG_SUPPORTED_OPTIONS=	debug doc tests valgrind
PKG_SUGGESTED_OPTIONS+=	# blank
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
BUILD_DEBUG=		--debug
.else
BUILD_DEBUG=		# blank
.endif

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DOC=		--docs
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
.else
BUILD_DOC=		# blank
.endif

.if !empty(PKG_OPTIONS:Mtests)
BUILD_TESTS=		--test
.else
BUILD_TESTS=		# blank
.endif

.if !empty(PKG_OPTIONS:Mvalgrind)
BUILD_VALGRIND=		--grind
BUILD_DEPENDS+=		valgrind-[0-9]*:../../devel/valgrind
.else
BUILD_VALGRIND=		# blank
.endif
