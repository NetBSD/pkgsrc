# $NetBSD: Makefile,v 1.22 2012/09/03 11:16:25 sno Exp $
#

DISTNAME=	WWW-Curl-4.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/WWW-Curl/
COMMENT=	Perl binding interface for curl
LICENSE=	mpl-1.0 OR mpl-1.1 OR mit

BUILDLINK_API_DEPENDS.curl+=	curl>=7.10.8

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/WWW/Curl/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../www/curl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
