# $NetBSD: options.mk,v 1.14 2013/05/10 20:07:34 riastradh Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ikiwiki
PKG_SUPPORTED_OPTIONS=		cvs ikiwiki-amazon-s3 ikiwiki-search
PKG_SUPPORTED_OPTIONS+=		imagemagick python svn w3m

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcvs)
. if !exists(/usr/bin/cvs)
DEPENDS+=	cvs-[0-9]*:../../devel/scmcvs
. endif
DEPENDS+=	cvsps-[0-9]*:../../devel/cvsps
DEPENDS+=	cvsweb-[0-9]*:../../www/cvsweb
DEPENDS+=	p5-File-chdir-[0-9]*:../../devel/p5-File-chdir
DEPENDS+=	p5-File-ReadBackwards-[0-9]*:../../textproc/p5-File-ReadBackwards
.endif

.if !empty(PKG_OPTIONS:Mikiwiki-search)
DEPENDS+=	p5-Search-Xapian-[0-9]*:../../textproc/p5-Search-Xapian
DEPENDS+=	xapian-omega-[0-9]*:../../textproc/xapian-omega
.endif

.if !empty(PKG_OPTIONS:Mikiwiki-amazon-s3)
DEPENDS+=	p5-Net-Amazon-S3-[0-9]*:../../net/p5-Net-Amazon-S3
DEPENDS+=	p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
.endif

.if !empty(PKG_OPTIONS:Mimagemagick)
DEPENDS+=	p5-PerlMagick-[0-9]*:../../graphics/p5-PerlMagick
.endif

.if !empty(PKG_OPTIONS:Mpython)
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
.else
PYTHON_FOR_BUILD_ONLY=	yes
.endif

.if !empty(PKG_OPTIONS:Msvn)
DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base
.endif

PLIST_VARS+=		w3m
.if !empty(PKG_OPTIONS:Mw3m)
DEPENDS+=		w3m-[0-9]*:../../www/w3m
PLIST.w3m=		yes
INSTALLATION_DIRS+=	share/doc/${PKGBASE}/w3mmode
post-install:
	${INSTALL_DATA} ${WRKSRC}/html/w3mmode.html \
		${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/w3mmode/ikiwiki.setup \
		${PREFIX}/share/doc/${PKGBASE}/w3mmode/ikiwiki.setup
.else
SUBST_CLASSES+=		w3m
SUBST_STAGE.w3m=	pre-configure
SUBST_FILES.w3m=	Makefile.PL
SUBST_SED.w3m+=		-e 's,^\(.*install .*W3M_CGI_BIN\),\#\1,'
.endif
