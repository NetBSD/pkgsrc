# $NetBSD: Makefile,v 1.10 2008/07/18 09:43:35 rhaen Exp $

DISTNAME=		CGI-Session-4.35
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ses
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module providing session management across HTTP requests

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CGI/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
