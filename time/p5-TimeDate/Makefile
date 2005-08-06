# $NetBSD: Makefile,v 1.12 2005/08/06 06:19:35 jlam Exp $
#

DISTNAME=      	TimeDate-1.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tid
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 TimeDate distribution

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/TimeDate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
