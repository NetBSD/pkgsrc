# $NetBSD: options.mk,v 1.1 2026/02/23 18:14:55 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-libxml2
PKG_SUPPORTED_OPTIONS=	doxygen

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoxygen)
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
TOOL_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
CONFIGURE_ARGS+=	--with-docs

mkdocxml: build
	${RUN} for f in ${WRKSRC}/doc/xml/*_8h.xml; do			\
	  ${SED} 's,${WRKDIR}/,,g' < $$f > ${FILESDIR}/$$(echo $$f | ${SED} 's,.*/,,');	\
	done

pre-build:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

.else

post-extract:
	${MKDIR} ${WRKSRC}/doc/xml
	${CP} ${FILESDIR}/*_8h.xml ${WRKSRC}/doc/xml

.endif
