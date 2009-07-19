# $NetBSD: Makefile,v 1.13 2009/07/19 10:58:17 sno Exp $
#

DISTNAME=	WWW-Curl-4.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/WWW-Curl/
COMMENT=	Perl binding interface for curl
#LICENSE=	MPL or MIT/X-derivat

BUILDLINK_API_DEPENDS.curl+=	curl>=7.10.8

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/WWW/Curl/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../www/curl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
