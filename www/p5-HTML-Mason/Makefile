# $NetBSD: Makefile,v 1.62 2022/06/28 11:37:22 wiz Exp $

DISTNAME=	HTML-Mason-1.59
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Mason
COMMENT=	Perl-based web site development and delivery system
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Cache-Cache>=1:../../devel/p5-Cache-Cache
DEPENDS+=	p5-Class-Container>=0.07:../../devel/p5-Class-Container
DEPENDS+=	p5-Exception-Class>=1.15:../../devel/p5-Exception-Class
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-Log-Any>=0.08:../../devel/p5-Log-Any
DEPENDS+=	p5-Params-Validate>=0.70:../../devel/p5-Params-Validate

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

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
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
