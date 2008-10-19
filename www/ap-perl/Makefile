# $NetBSD: Makefile,v 1.44 2008/10/19 19:19:01 he Exp $
#

DISTNAME=		mod_perl-1.29
PKGNAME=		ap13-perl-1.29
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/} \
			http://perl.apache.org/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://perl.apache.org/
COMMENT=		Module that embeds a Perl interpreter into Apache

CONFLICTS=		ap-perl-[0-9]*
CONFLICTS+=		ap2-perl-[0-9]*

DEPENDS+=		${BUILDLINK_API_DEPENDS.apache}:../../www/apache
DEPENDS+=		p5-BSD-Resource>=1.10:../../devel/p5-BSD-Resource

APACHE_MODULE=		YES
PERL5_PACKLIST=		auto/mod_perl/.packlist

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}
MAKE_PARAMS+=		EVERYTHING=1

.include "../../lang/perl5/module.mk"
.include "../../www/apache/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/manual/mod
	${INSTALL_DATA} ${WRKSRC}/htdocs/manual/mod/mod_perl.html \
		${PREFIX}/share/httpd/htdocs/manual/mod

.include "../../mk/bsd.pkg.mk"
