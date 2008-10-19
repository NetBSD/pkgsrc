# $NetBSD: Makefile,v 1.4 2008/10/19 19:19:07 he Exp $

DISTNAME=		FCGI-ProcManager-0.18
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JU/JURACH/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/FCGI-ProcManager/
COMMENT=		Functions for managing FastCGI applications

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/FCGI/ProcManager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
