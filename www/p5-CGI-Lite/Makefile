# $NetBSD: Makefile,v 1.3 2010/08/21 16:36:36 seb Exp $
#

DISTNAME=		CGI-Lite-2.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cgl
PKGREVISION=		3
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Lite/
COMMENT=		Simple perl5 module for writing forms-based CGI programs

PREV_PKGPATH=		www/p5-CGI_Lite
SUPERSEDES=		p5-CGI_Lite-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/CGI/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
