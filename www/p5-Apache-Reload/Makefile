# $NetBSD: Makefile,v 1.11 2011/04/04 09:26:00 adam Exp $

DISTNAME=	Apache-Reload-0.11
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5arl
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

HOMEPAGE=	http://search.cpan.org/dist/Apache-Reload/
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to reload changed modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/apache.mk"

.if (${PKG_APACHE} == "apache13")
PERL5_PACKLIST=		auto/Apache/Reload/.packlist
.else
PERL5_PACKLIST=		auto/Apache2/Reload/.packlist
.endif

.if (${PKG_APACHE} == "apache13")
.include "../../www/ap-perl/buildlink3.mk"
.else
.include "../../www/ap2-perl/buildlink3.mk"
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
