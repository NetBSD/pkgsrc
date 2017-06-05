# $NetBSD: Makefile,v 1.14 2017/06/05 14:25:03 ryoon Exp $

DISTNAME=	DateTime-Format-HTTP-0.42
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-HTTP/
COMMENT=	Deal with date formats used by HTTP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.17:../../time/p5-DateTime
DEPENDS+=	p5-libwww>=1.44:../../www/p5-libwww

PERL5_PACKLIST=	auto/DateTime/Format/HTTP/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
