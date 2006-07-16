# $NetBSD: Makefile,v 1.14 2006/07/16 13:23:52 heinz Exp $
#

DISTNAME=      	TimeDate-1.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tid
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 TimeDate distribution

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/TimeDate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
