# $NetBSD: Makefile,v 1.23 2022/06/28 11:37:27 wiz Exp $

DISTNAME=	HTTP-Daemon-6.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Daemon
COMMENT=	Simple http server class
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00

DEPENDS+=	p5-HTTP-Date>=6:../../www/p5-HTTP-Date
DEPENDS+=	p5-HTTP-Message>=6.02:../../www/p5-HTTP-Message
DEPENDS+=	p5-LWP-MediaTypes>=6.01:../../www/p5-LWP-MediaTypes
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/HTTP/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
