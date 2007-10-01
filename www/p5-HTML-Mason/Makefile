# $NetBSD: Makefile,v 1.28 2007/10/01 21:29:32 heinz Exp $

DISTNAME=		HTML-Mason-1.3101
PKGNAME=		p5-HTML-Mason-1.31.1
PKGREVISION=		4
SVR4_PKGNAME=		p5hma
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.masonhq.com/
COMMENT=		Perl-based web site development and delivery system

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Cache-Cache>=1.0:../../devel/p5-Cache-Cache
DEPENDS+=		p5-Params-Validate>=0.04:../../devel/p5-Params-Validate
DEPENDS+=		p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=		p5-Class-Container>=0.10:../../devel/p5-Class-Container

USE_LANGUAGES=		# empty

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/Mason/.packlist

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-HTML-Mason
PKG_SUPPORTED_OPTIONS=	modperl
PKG_SUGGESTED_OPTIONS=	modperl

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmodperl)
.  include "../../mk/apache.mk"
.  if ${PKG_APACHE} == "apache13"
DEPENDS+=	p5-libapreq>=0.32:../../www/p5-libapreq
.    include "../../www/ap-perl/buildlink3.mk"
.  elif ${PKG_APACHE} == "apache2" || ${PKG_APACHE} == "apache22"
DEPENDS+=	p5-libapreq2-[0-9]*:../../www/p5-libapreq2
.    include "../../www/ap2-perl/buildlink3.mk"
.  endif
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${EGDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/samples/README ${DESTDIR:Q}${EGDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/samples/dump-request ${DESTDIR:Q}${EGDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/samples/show-env ${DESTDIR:Q}${EGDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/eg/httpd.conf ${DESTDIR:Q}${EGDIR:Q}
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${EGDIR:Q}/MyApp
	${INSTALL_DATA} ${WRKSRC}/eg/MyApp/* ${DESTDIR:Q}${EGDIR:Q}/MyApp

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
