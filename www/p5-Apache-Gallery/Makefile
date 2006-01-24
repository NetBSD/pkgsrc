# $NetBSD: Makefile,v 1.32 2006/01/24 07:32:49 wiz Exp $
#

DISTNAME=	Apache-Gallery-0.9.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5aga
CATEGORIES=	www graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://apachegallery.dk/
COMMENT=	Perl5/Apache module for handling image directories

DEPENDS+=	p5-CGI>=2.93:../../www/p5-CGI
DEPENDS+=	p5-URI>=1.23:../../www/p5-URI
DEPENDS+=	p5-Image-Imlib2-[0-9]*:../../graphics/p5-Image-Imlib2
DEPENDS+=	p5-Image-Info>=1.15:../../graphics/p5-Image-Info
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template
DEPENDS+=	p5-libapreq{,2}-[0-9]*:../../www/${LIBAPREQ}

PERL5_PACKLIST=		auto/Apache/Gallery/.packlist

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

.if defined(PKG_APACHE_DEFAULT) && (${PKG_APACHE_DEFAULT} == "apache2")
LIBAPREQ=		p5-libapreq2
.else
LIBAPREQ=		p5-libapreq
.endif

AG=			ag
AG_DOCDIR=		${PREFIX}/share/doc/${AG}
AG_EGDIR=		${PREFIX}/share/examples/${AG}
AG_SHAREDIR=		${PREFIX}/share/${AG}

FILES_SUBST+=		LDFLAGS=${LDFLAGS:M*:Q}

MESSAGE_SUBST+=		AG=${AG}
MESSAGE_SUBST+=		AG_DOCDIR=${AG_DOCDIR}
MESSAGE_SUBST+=		AG_SHAREDIR=${AG_SHAREDIR}

PLIST_SUBST+=		AG=${AG:Q}
PLIST_SUBST+=		AG_DOCDIR=${AG_DOCDIR:S,${PREFIX}/,,}
PLIST_SUBST+=		AG_EGDIR=${AG_EGDIR:S,${PREFIX}/,,}
PLIST_SUBST+=		AG_SHAREDIR=${AG_SHAREDIR:S,${PREFIX}/,,}

CONF_FILES=		${AG_EGDIR}/${AG}.conf ${PKG_SYSCONFDIR}/${AG}.conf

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	ag.conf
SUBST_SED.paths+=	-e 's,@AG@,${AG},g'
SUBST_SED.paths+=	-e 's,@AG_SHAREDIR@,${AG_SHAREDIR},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/ag.conf ${WRKSRC}

post-patch:
	@${MV} -f ${WRKSRC}/templates/default/gallery.css \
	    ${WRKSRC}/htdocs/gallery-default.css
	@${MV} -f ${WRKSRC}/templates/new/gallery.css \
	    ${WRKSRC}/htdocs/gallery-new.css

post-build:
	@for j in default new; \
	do \
	    cd ${WRKSRC}/templates/$$j && \
	    for i in *.tpl; \
	    do \
		${CP} -p $$i $$i.orig && \
		${SED} -e "s,/icons/,/${AG}/," \
		       -e "s,/gallery.css,/${AG}/gallery-$$j.css," \
		    $$i.orig > $$i; \
		${RM} -f $$i.orig; \
	    done; \
	done

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
	${INSTALL_DATA} ${WRKSRC}/${AG}.conf ${AG_EGDIR}

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
