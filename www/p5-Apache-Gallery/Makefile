# $NetBSD: Makefile,v 1.1.1.1 2002/09/01 22:42:49 kim Exp $
#

DISTNAME=	Apache-Gallery-0.4.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5aga
CATEGORIES=	www graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://apachegallery.dk/
COMMENT=	perl5/Apache module for handling image directories

DEPENDS+=	ap-perl>=1.25:../../www/ap-perl
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-Image-Info-[0-9]*:../../graphics/p5-Image-Info
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
DEPENDS+=	p5-CGI-FastTemplate-[0-9]*:../../www/p5-CGI-FastTemplate
DEPENDS+=	p5-Inline-[0-9]*:../../devel/p5-Inline
DEPENDS+=	p5-libapreq-[0-9]*:../../www/p5-libapreq
DEPENDS+=	imlib2-[0-9]*:../../graphics/imlib2

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Gallery/.packlist

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

AG=			ag
AG_DOCDIR=		${PREFIX}/share/doc/${AG}
AG_EGDIR=		${PREFIX}/share/examples/${AG}
AG_SHAREDIR=		${PREFIX}/share/${AG}

FILES_SUBST+=		AG=${AG}
FILES_SUBST+=		AG_SHAREDIR=${AG_SHAREDIR}

MESSAGE_SUBST+=		AG=${AG}
MESSAGE_SUBST+=		AG_DOCDIR=${AG_DOCDIR}
MESSAGE_SUBST+=		AG_SHAREDIR=${AG_SHAREDIR}

PLIST_SUBST+=		AG=${AG}
PLIST_SUBST+=		AG_DOCDIR=${AG_DOCDIR:S,${PREFIX}/,,}
PLIST_SUBST+=		AG_EGDIR=${AG_EGDIR:S,${PREFIX}/,,}
PLIST_SUBST+=		AG_SHAREDIR=${AG_SHAREDIR:S,${PREFIX}/,,}

CONF_FILES=		${AG_EGDIR}/${AG}.conf ${PKG_SYSCONFDIR}/${AG}.conf

post-patch:
	@cd ${WRKSRC}/lib/Apache && \
	${CP} -p Gallery.pm Gallery.pm.orig && \
	${SED} ${FILES_SUBST_SED} Gallery.pm.orig > Gallery.pm && \
	${RM} -f Gallery.pm.orig

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-build:
	@cd ${WRKSRC}/templates; \
	for i in *.tpl; \
	do \
	    ${CP} -p $$i $$i.orig && \
	    ${SED} -e 's,/icons/,/${AG}/,' \
		   -e 's,/gallery.css,/${AG}/gallery.css,' \
		$$i.orig > $$i; \
	    ${RM} -f $$i.orig; \
	done
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/ag.conf > ${WRKDIR}/${AG}.conf

post-install:
	${INSTALL_DATA_DIR} ${AG_SHAREDIR}
	@set +x; \
	for i in htdocs templates; \
	do \
	    ${INSTALL_DATA_DIR} ${AG_SHAREDIR}/$$i; \
	    cd ${WRKSRC}/$$i && ${PAX} -rw . ${AG_SHAREDIR}/$$i; \
	done; \
	${INSTALL_DATA_DIR} ${AG_DOCDIR}; \
	for i in Changes INSTALL LICENSE README UPGRADE; \
	do \
	    ${INSTALL_DATA} ${WRKSRC}/$$i ${AG_DOCDIR}; \
	done
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${AG_SHAREDIR}; \
	${INSTALL_DATA_DIR} ${AG_EGDIR}
	${INSTALL_DATA} ${WRKDIR}/${AG}.conf ${AG_EGDIR}

.include "../../pkgtools/x11-links/xfree.buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
