# $NetBSD: Makefile,v 1.38 2011/08/14 16:05:53 obache Exp $

DISTNAME=	HTML-Mason-1.45
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5hma
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://www.masonhq.com/
COMMENT=	Perl-based web site development and delivery system
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Cache-Cache>=1:../../devel/p5-Cache-Cache
DEPENDS+=	p5-Class-Container>=0.07:../../devel/p5-Class-Container
DEPENDS+=	p5-Exception-Class>=1.15:../../devel/p5-Exception-Class
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-Log-Any>=0.08:../../devel/p5-Log-Any
DEPENDS+=	p5-Params-Validate>=0.70:../../devel/p5-Params-Validate

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/Mason/.packlist

.include "options.mk"

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
