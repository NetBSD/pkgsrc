# $NetBSD: Makefile,v 1.1 2026/09/09 11:07:48 markd Exp $

DISTNAME=	LWP-Protocol-http-SocketUnixAlt-0.0204
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHARYANTO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/LWP::Protocol::http::SocketUnixAlt
COMMENT=	Speak HTTP through Unix sockets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Protocol/http/SocketUnixAlt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
