# $NetBSD: Makefile,v 1.2 2009/05/01 21:08:41 sno Exp $

DISTNAME=	DateTime-Format-HTTP-0.38
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-HTTP/
COMMENT=	Deal with date formats used by HTTP
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime>=0.17:../../time/p5-DateTime
DEPENDS+=	p5-libwww>=1.44:../../www/p5-libwww

PERL5_PACKLIST=	auto/DateTime/Format/HTTP/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
