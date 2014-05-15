# $NetBSD: Makefile,v 1.14 2014/05/15 11:59:21 wiz Exp $

DISTNAME=	LWP-Protocol-https-6.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHILLI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LWP-Protocol-https/
COMMENT=	Provide https support for LWP::UserAgent
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.02

DEPENDS+=	p5-IO-Socket-SSL>=1.38:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Mozilla-CA>=20110101:../../security/p5-Mozilla-CA
# needed for tests, but p5-libwww depends on this package
#DEPENDS+=	p5-libwww>=6.06:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Protocol/https/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
