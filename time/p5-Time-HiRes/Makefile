# $NetBSD: Makefile,v 1.12 2003/12/28 00:27:08 heinz Exp $
#

DISTNAME=		Time-HiRes-1.52
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5thr
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://search.cpan.org/author/JHI/Time-HiRes/
COMMENT=		Perl5 module for high resolution time, sleep, and alarm

USE_BUILDLINK2=		YES

PERL5_CONFIGURE=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time/HiRes/.packlist

pre-configure:
	@ # On Solaris link against librt to pull in nanosleep
	@ ${ECHO} "\$$self->{LIBS} = ['-lrt'];" >> ${WRKSRC}/hints/solaris.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
