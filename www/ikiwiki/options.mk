# $NetBSD: options.mk,v 1.1 2009/04/21 16:34:43 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ikiwiki
PKG_SUPPORTED_OPTIONS=		ikiwiki-amazon-s3 ikiwiki-search
PKG_SUPPORTED_OPTIONS+=		imagemagick python svn w3m
PKG_OPTIONS_LEGACY_OPTS+=	amazon_s3:ikiwiki-amazon-s3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mikiwiki-search)
DEPENDS+=	p5-Search-Xapian-[0-9]*:../../textproc/p5-Search-Xapian
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
.endif

.if !empty(PKG_OPTIONS:Mikiwiki-amazon-s3)
DEPENDS+=	p5-Net-Amazon-S3-[0-9]*:../../net/p5-Net-Amazon-S3
DEPENDS+=	p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
.endif

.if !empty(PKG_OPTIONS:Mimagemagick)
DEPENDS+=	p5-PerlMagick-[0-9]*:../../graphics/p5-PerlMagick
.endif

.if !empty(PKG_OPTIONS:Mpython)
REPLACE_PYTHON+=plugins/proxy.py plugins/rst
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
.include "../../lang/python/application.mk"
.endif

.if !empty(PKG_OPTIONS:Msvn)
DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base
.endif

PLIST_VARS+=		w3m
.if !empty(PKG_OPTIONS:Mw3m)
DEPENDS+=		w3m-[0-9]*:../../www/w3m
PLIST.w3m=		yes
SUBST_SED.makefile+=	-e 's,/lib/w3m/cgi-bin,/libexec/w3m/cgi-bin,'
INSTALLATION_DIRS+=	share/doc/${PKGBASE}/w3mmode
post-install:
	${INSTALL_DATA} ${WRKSRC}/html/w3mmode.html \
		${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/w3mmode/ikiwiki.setup \
		${PREFIX}/share/doc/${PKGBASE}/w3mmode/ikiwiki.setup
.else
SUBST_SED.makefile+=	-e 's,^\(.*install .*W3M_CGI_BIN\),\#\1,'
.endif
