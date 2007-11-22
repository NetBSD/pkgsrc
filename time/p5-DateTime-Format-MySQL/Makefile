# $NetBSD: Makefile,v 1.2 2007/11/22 02:56:03 jnemeth Exp $

DISTNAME=	DateTime-Format-MySQL-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-MySQL/
COMMENT=	Parse and format MySQL dates and times

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/Format/MySQL/.packlist

DEPENDS+=	p5-DateTime-Format-Builder>=0.7807:../../time/p5-DateTime-Format-Builder

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
