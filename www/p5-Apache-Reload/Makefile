# $NetBSD: Makefile,v 1.5 2005/08/06 06:19:36 jlam Exp $
#

DISTNAME=		Apache-Reload-0.07
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5arl
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
COMMENT=		Perl5 module to reload changed modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Apache/Reload/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
