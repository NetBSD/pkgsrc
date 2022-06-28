# $NetBSD: Makefile,v 1.14 2022/06/28 11:37:36 wiz Exp $
#

DISTNAME=	LWPx-TimedHTTP-1.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWPx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LWPx-TimedHTTP
COMMENT=	Perl 5 module to time the different stages of an HTTP request
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-libwww>=6.0:../../www/p5-libwww

BUILD_DEPENDS+=		p5-HTTP-Daemon-[0-9]*:../../www/p5-HTTP-Daemon

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/LWPx/TimedHTTP/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
