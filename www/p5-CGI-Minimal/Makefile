# $NetBSD: Makefile,v 1.15 2007/12/16 07:11:51 rhaen Exp $

DISTNAME=		CGI-Minimal-1.29
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cgm
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Minimal/
COMMENT=		Perl5 module for simple CGI scripts

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/CGI/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
