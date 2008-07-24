# $NetBSD: Makefile,v 1.3 2008/07/24 09:33:33 rhaen Exp $

DISTNAME=		FCGI-ProcManager-0.18
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JU/JURACH/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/FCGI-ProcManager/
COMMENT=		Functions for managing FastCGI applications

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/FCGI/ProcManager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
