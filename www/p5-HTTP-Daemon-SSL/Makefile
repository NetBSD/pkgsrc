# $NetBSD: Makefile,v 1.2 2024/11/16 12:07:44 wiz Exp $

DISTNAME=	HTTP-Daemon-SSL-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AU/AUFFLICK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Daemon-SSL
COMMENT=	Simple http server class with SSL support
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-HTTP-Daemon-[0-9]*:../../www/p5-HTTP-Daemon

PERL5_PACKLIST=		auto/HTTP/Daemon/SSL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
