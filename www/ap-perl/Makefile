# $NetBSD: Makefile,v 1.48 2011/08/14 16:05:39 obache Exp $
#

DISTNAME=		mod_perl-1.29
PKGNAME=		ap13-perl-1.29
PKGREVISION=		4
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/} \
			http://perl.apache.org/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://perl.apache.org/
COMMENT=		Module that embeds a Perl interpreter into Apache

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		ap-perl-[0-9]*
CONFLICTS+=		ap2-perl-[0-9]*

DEPENDS+=		${BUILDLINK_API_DEPENDS.apache}:../../www/apache
DEPENDS+=		p5-BSD-Resource>=1.10:../../devel/p5-BSD-Resource

APACHE_MODULE=		YES
PERL5_PACKLIST=		auto/mod_perl/.packlist

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}
MAKE_PARAMS+=		EVERYTHING=1

INSTALLATION_DIRS+=	lib/httpd share/httpd/htdocs/manual/mod

.include "../../lang/perl5/module.mk"
.include "../../www/apache/buildlink3.mk"

post-install:
	${INSTALL_LIB} ${WRKSRC}/apaci/libperl.so \
	    ${DESTDIR}${PREFIX}/lib/httpd/mod_perl.so
	${INSTALL_DATA} ${WRKSRC}/htdocs/manual/mod/mod_perl.html \
	    ${DESTDIR}${PREFIX}/share/httpd/htdocs/manual/mod

.include "../../mk/bsd.pkg.mk"
